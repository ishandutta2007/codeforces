# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

T=int(input())
for Tid in range(T):
    n,k=map(int,input().split())
    a=array.array('i',map(int,input().split()))
    a=sorted(a)
    ans=0
    for i in range(1,n):
        ans=ans+(k-a[i])//a[0];
    print(ans)