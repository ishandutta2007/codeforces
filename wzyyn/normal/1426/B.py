# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

T=int(input())
for Tid in range(T):
    n,m=map(int,input().split())
    fl1=0
    for i in range(n):
        a11,a12=map(int,input().split())
        a21,a22=map(int,input().split())
        if a12==a21:
            fl1=1
    if m%2:
        print("NO")
    else:
        if fl1:
            print("YES")
        else:
            print("NO")