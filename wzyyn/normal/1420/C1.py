# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import functools
import math

T=int(input())

for Tid in range(T):
    n,Q=map(int,input().split())
    a=list(map(int,input().split()))
    f0=0
    f1=-1e18
    for i in range(n):
        tmp=max(f0,f1-a[i])
        f1=max(f1,f0+a[i])
        f0=tmp
    print(f1)