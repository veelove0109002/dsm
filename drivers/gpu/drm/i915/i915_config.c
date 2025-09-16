// SPDX-License-Identifier: MIT
/*
 * Copyright © 2020 Intel Corporation
 */

#include <linux/kernel.h>

#include "i915_config.h"
#include "i915_utils.h"

unsigned long
i915_fence_context_timeout(const struct drm_i915_private *i915, u64 context)
{
	/* Some downstream kernels may not define CONFIG_DRM_I915_FENCE_TIMEOUT. */
	#if defined(CONFIG_DRM_I915_FENCE_TIMEOUT) && (CONFIG_DRM_I915_FENCE_TIMEOUT)
	if (context)
		return msecs_to_jiffies_timeout(CONFIG_DRM_I915_FENCE_TIMEOUT);
	#endif

	return 0;
}
