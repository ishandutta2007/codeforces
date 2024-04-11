# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

T=int(input())
for Tid in range(T):
    n,k=map(int,input().split())
    if n<=2:
        print(1)
    else:
        print((n-2+k-1)//k+1)