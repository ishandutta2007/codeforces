#!/usr/bin/env python
# coding=utf-8
n = input()
y = n.split("WUB")
j = []
for i in y:
    if i != "":
        j.append(i)
s = " ".join(j)
print(s)