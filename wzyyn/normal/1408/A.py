# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

mo=1000000007

T=int(input())
for Tid in range(T):
    n=int(input())
    a=array.array('i',map(int,input().split()))
    b=array.array('i',map(int,input().split()))
    c=array.array('i',map(int,input().split()))
    fi=a[0]
    la=a[0]
    print(a[0],end=' ')
    for i in range(1,n):
        v=0
        if a[i]!=fi and a[i]!=la:
            v=a[i]
        if b[i]!=fi and b[i]!=la:
            v=b[i]
        if c[i]!=fi and c[i]!=la:
            v=c[i]
        print(v,end=' ')
        la=v
    print()