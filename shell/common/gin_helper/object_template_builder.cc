// Copyright (c) 2019 GitHub, Inc. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "shell/common/gin_helper/object_template_builder.h"

namespace gin_helper {

ObjectTemplateBuilder::ObjectTemplateBuilder(
    v8::Isolate* isolate,
    v8::Local<v8::ObjectTemplate> templ)
    : isolate_(isolate), template_(templ) {}

ObjectTemplateBuilder::~ObjectTemplateBuilder() = default;

ObjectTemplateBuilder& ObjectTemplateBuilder::SetImpl(
    const base::StringPiece& name,
    v8::Local<v8::Data> val) {
  template_->Set(gin::StringToSymbol(isolate_, name), val);
  return *this;
}

ObjectTemplateBuilder& ObjectTemplateBuilder::SetPropertyImpl(
    const base::StringPiece& name,
    v8::Local<v8::FunctionTemplate> getter,
    v8::Local<v8::FunctionTemplate> setter) {
  template_->SetAccessorProperty(gin::StringToSymbol(isolate_, name), getter,
                                 setter);
  return *this;
}

}  // namespace gin_helper
