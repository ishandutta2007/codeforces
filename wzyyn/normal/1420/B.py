# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import functools
import math

T=int(input())

for Tid in range(T):
    n=int(input())
    a=list(map(int,input().split()))
    tab=[0 for i in range(35)]
    ans=0
    for i in range(n):
        j=0
        while (2<<j)<=a[i]:
            j=j+1
        ans=ans+tab[j]
        # print(j,end=' ')
        tab[j]=tab[j]+1
    print(ans)