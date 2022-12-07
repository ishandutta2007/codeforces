# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

mo=1000000007

T=int(input())
for Tid in range(T):
    n,k=map(int,input().split())
    a=array.array('i',map(int,input().split()))
    
    def query(x):
        la=0
        rem=x
        ans=0
        for i in range(n):
            T=min((a[i]-la)/(i+1),rem)
            ans=ans+T*(i+1)
            rem=rem-T
            la=a[i]
        ans=ans+rem*(n+1)
        
        la=k
        rem=x
        for i in range(n-1,-1,-1):
            T=min((la-a[i])/(n-i),rem)
            ans=ans+T*(n-i)
            rem=rem-T
            la=a[i]
        ans=ans+rem*(n+1)
        return ans
    
    l=0.0
    r=1.0*k
    for i in range(60):
        mid=(l+r)/2
        if (query(mid)>=k):
            r=mid
        else:
            l=mid
    print((l+r)/2)