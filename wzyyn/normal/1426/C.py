# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

T=int(input())
for Tid in range(T):
    n=int(input())
    ans=1<<30
    m=max(1,int(n**0.5)-5)
    for i in range(10):
        ans=min(ans,m+(n+m-1)//m-2)
        m=m+1
    print(ans)