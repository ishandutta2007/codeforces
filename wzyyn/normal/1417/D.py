# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

T=int(input())
for Tid in range(T):
    n=int(input())
    a=array.array('i',map(int,input().split()))
    x=array.array('i');
    y=array.array('i');
    z=array.array('i');
    s=0
    for i in range(n):
        s=s+a[i]
    if s%n:
        print(-1)
        continue
    len=0
    for i in range(1,n):
        rem=a[i]%(i+1)
        if rem:
            key=(i+1)-rem
            x.append(1)
            y.append(i+1)
            z.append(key)
            a[i]=a[i]+key
            len=len+1
        x.append(i+1)
        y.append(1)
        z.append(a[i]//(i+1))
        len=len+1
    for i in range(1,n):
        x.append(1)
        y.append(i+1)
        z.append(s//n)
        len=len+1
    print(len)
    for i in range(len):
        print(x[i],y[i],z[i])