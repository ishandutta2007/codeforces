# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

n=int(input())
a=array.array('i',map(int,input().split()))
s=0
q=[]
q.append(0)
for i in range(n):
    if a[i]==1:
        q.append(i+1)
        s=s+1
q.append(n+1)
m=n*(n-1)//2
f=[[10000000 for i in range(82)] for i in range(3500)]
f[0][0]=0
for i in range(1,s+2):
    rlim=n+1-(s+1-i)
    g=[[10000000 for i in range(82)] for i in range(3500)]
    for j in range(i-1,rlim+1):
        for S in range(m+1):
            if (f[S][j]<1000000):
                for k in range(j+1,rlim+1):
                    nv=f[S][j]+(k-j-1)*(k-j-2)//2
                    nS=S+abs(k-q[i])
                    g[nS][k]=min(g[nS][k],nv)
    f=g
mn=0
for i in range(m+1):
    mn=max(mn,(n-s)*(n-s-1)//2-f[i][n+1])
    print(mn,end=' ')