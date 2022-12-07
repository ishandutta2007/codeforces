# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

N=1000005;
n,m=map(int,input().split())
a=array.array('i',[0 for i in range(n)])
b=array.array('i',[0 for i in range(n)])
c=array.array('i',[0 for i in range(m)])
d=array.array('i',[0 for i in range(m)])
for i in range(n):
    a[i],b[i]=map(int,input().split())
for i in range(m):
    c[i],d[i]=map(int,input().split())
re=array.array('i',[0 for i in range(N)])
for i in range(n):
    for j in range(m):
        if a[i]<=c[j] and b[i]<=d[j]:
            key=c[j]-a[i]
            re[key]=max(re[key],d[j]-b[i]+1)

for i in range(N-1,0,-1):
    re[i-1]=max(re[i-1],re[i])

ans=1<<30
for i in range(N):
    ans=min(ans,re[i]+i)

print(ans)