//
// Copyright 2019 Le Hoang Quyen. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// We don't use GLES from Apple framework.
// Instead we use GLES provided by MetalANGLE.
#define GLES_SILENCE_DEPRECATION
#define GL_SILENCE_DEPRECATION

#import <Foundation/Foundation.h>
#import <QuartzCore/CALayer.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MGLContext;

typedef enum MGLDrawableColorFormat : int
{
    MGLDrawableColorFormatRGBA8888 = 32,
    MGLDrawableColorFormatRGB565   = 16,
} MGLDrawableColorFormat;

typedef enum MGLDrawableStencilFormat : int
{
    MGLDrawableStencilFormatNone = 0,
    MGLDrawableStencilFormat8    = 8,
} MGLDrawableStencilFormat;

typedef enum MGLDrawableDepthFormat : int
{
    MGLDrawableDepthFormatNone = 0,
    MGLDrawableDepthFormat16   = 16,
    MGLDrawableDepthFormat24   = 24,
} MGLDrawableDepthFormat;

@interface MGLLayer : CALayer

// Return the size of the OpenGL framebuffer.
@property(readonly) CGSize drawableSize;

@property(nonatomic) MGLDrawableColorFormat drawableColorFormat;      // Default is RGBA8888
@property(nonatomic) MGLDrawableDepthFormat drawableDepthFormat;      // Default is DepthNone
@property(nonatomic) MGLDrawableStencilFormat drawableStencilFormat;  // Default is StencilNone

- (BOOL)setCurrentContext:(MGLContext *)context;
// Present the content of OpenGL backed framebuffer on screen as soon as possible.
- (BOOL)present;

@end

NS_ASSUME_NONNULL_END
