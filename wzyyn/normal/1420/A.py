# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import functools
import math

T=int(input())

for Tid in range(T):
    n=int(input())
    a=list(map(int,input().split()))
    flag=0
    for i in range(1,n):
        if a[i]>=a[i-1]:
            flag=1
    if flag:
        print("YES")
    else:
        print("NO")