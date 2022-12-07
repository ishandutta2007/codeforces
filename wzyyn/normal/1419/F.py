# import numpy as npy
import functools
import math

n=int(input())
x=[0 for i in range(n+2)]
y=[0 for i in range(n+2)]
adj=[[] for i in range(n+2)]
idx=[]
idy=[]
for i in range(n):
    x[i],y[i]=map(int,input().split())
    idx.append(i)
    idy.append(i)

def cmpx(a,b):
    if x[a]!=x[b]:
        if x[a]<x[b]:
            return -1
        else:
            return 1
    if y[a]!=y[b]:
        if y[a]<y[b]:
            return -1
        else:
            return 1
    return 0
    
def cmpy(a,b):
    if y[a]!=y[b]:
        if y[a]<y[b]:
            return -1
        else:
            return 1
    if x[a]!=x[b]:
        if x[a]<x[b]:
            return -1
        else:
            return 1
    return 0

idx=sorted(idx,key=functools.cmp_to_key(cmpx))
idy=sorted(idy,key=functools.cmp_to_key(cmpy))

# print(idx)
# print(idy)

def disx(a,b):
    if x[a]!=x[b]:
        return 1e18
    return y[b]-y[a]
    
def disy(a,b):
    if y[a]!=y[b]:
        return 1e18
    return x[b]-x[a]

l=0
r=2000000000
ans=-1

while l<=r:
    # print(l,r)
    mid=(l+r)//2
    for i in range(n):
        adj[i]=[]
    for i in range(n-1):
        if disx(idx[i],idx[i+1])<=mid:
            adj[idx[i]].append(idx[i+1])
            adj[idx[i+1]].append(idx[i])
            # print(idx[i],idx[i+1])
        if disy(idy[i],idy[i+1])<=mid:
            adj[idy[i]].append(idy[i+1])
            adj[idy[i+1]].append(idy[i])
            # print(idy[i],idy[i+1])
    col=[0 for i in range(n)]
    cur=0
    def dfs(x):
        col[x]=cur
        for i in range(len(adj[x])):
            if col[adj[x][i]]==0:
                dfs(adj[x][i])
    for i in range(n):
        if col[i]==0:
            cur=cur+1
            dfs(i)
    ok=0
    if cur>4:
        ok=0
    if cur==1:
        ok=1
    if cur==2:
        for i in range(n):
            for j in range(i+1,n):
                if (col[i]!=col[j]):
                    d1=abs(x[i]-x[j])
                    d2=abs(y[i]-y[j])
                    if d1==0 or d2==0:
                        if d1+d2<=2*mid:
                            ok=1
                    if d1<=mid and d2<=mid:
                        ok=1
    if cur==3:
        for i in range(n-1):
            px=idx[i]
            py=idx[i+1]
            if x[px]==x[py] and col[px]!=col[py]:
                for j in range(n):
                    if col[px]!=col[j] and col[py]!=col[j]:
                        d1=abs(y[px]-y[j])
                        d2=abs(y[py]-y[j])
                        d3=abs(x[px]-x[j])
                        if d1<=mid and d2<=mid and d3<=mid:
                            ok=1
        for i in range(n-1):
            px=idy[i]
            py=idy[i+1]
            if y[px]==y[py] and col[px]!=col[py]:
                for j in range(n):
                    if col[px]!=col[j] and col[py]!=col[j]:
                        d1=abs(x[px]-x[j])
                        d2=abs(x[py]-x[j])
                        d3=abs(y[px]-y[j])
                        if d1<=mid and d2<=mid and d3<=mid:
                            ok=1
    if cur==4:
        for i in range(n-1):
            px=idx[i]
            py=idx[i+1]
            if x[px]==x[py] and col[px]!=col[py]:
                for j in range(n-1):
                    pz=idy[j]
                    pw=idy[j+1]
                    if y[pz]==y[pw] and col[pz]!=col[pw]:
                        if col[pz]!=col[px] and col[pz]!=col[py]:
                            if col[pw]!=col[px] and col[pw]!=col[py]:
                                d1=abs(y[px]-y[pz])
                                d2=abs(y[py]-y[pz])
                                d3=abs(x[pz]-x[px])
                                d4=abs(x[pw]-x[px])
                                if d1<=mid and d2<=mid and d3<=mid and d4<=mid:
                                    ok=1
    if ok:
        ans=mid
        r=mid-1
    else:
        l=mid+1
print(ans)