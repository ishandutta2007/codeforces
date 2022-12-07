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
    b=array.array('i',[0 for i in range(n+2)])
    la=array.array('i',[-1 for i in range(n+2)])
    for i in range(n):
        b[a[i]]=max(b[a[i]],i-la[a[i]]);
        la[a[i]]=i
    for i in range(1,n+1):
        b[i]=max(b[i],n-la[i]);
    ans=array.array('i',[1<<30 for i in range(n+2)])
    for i in range(1,n+1):
        ans[b[i]]=min(ans[b[i]],i);
    for i in range(1,n+1):
        ans[i]=min(ans[i],ans[i-1])
    for i in range(1,n+1):
        if ans[i]==1<<30:
            ans[i]=-1;
        print(ans[i],end=' ');
    print()