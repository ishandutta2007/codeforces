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
    b=array.array('i',[0 for i in range(n)])
    s=0
    for i in range(n):
        if a[i]*2==k:
            s=s+1
        else:
            if a[i]*2<k:
                b[i]=1
    s=(s+1)//2;
    for i in range(n):
        if a[i]*2==k and s!=0:
            s=s-1
            b[i]=1
        print(b[i],end=' ')
    print()