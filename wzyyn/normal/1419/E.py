# import numpy as npy
import math
T=int(input())

def construct1(a,p):
    v=1
    for i in range(0,p[0]):
        v=v*a[0]
        print(v,end=' ')
    print(a[1]*a[0],end=' ')
    v=1
    for i in range(1,p[1]+1):
        v=v*a[1]
        vv=v
        for j in range(0,p[0]+1):
            if i!=1 or j!=1:
                print(vv,end=' ')
            vv=vv*a[0]
    print()
    print(0)
    
def construct2(a,p):
    m=len(a)
    spe=a[0]*a[m-1]
    def dfs(x,v):
        if (x>=m):
            if v!=spe and v!=1:
                print(v,end=' ')
            return 0
        t=v;
        for i in range(p[x]+1):
            dfs(x+1,v)
            v=v*a[x]
            
    for i in range(m):
        v=1
        for j in range(p[i]):
            v=v*a[i]
            dfs(i+1,v)
    print(spe)
    print(0)

for Tid in range(T):
    n=int(input())
    s=2
    a=[]
    p=[]
    while s*s<=n:
        if n%s==0:
            a.append(s)
            t=0
            while n%s==0:
                n=n//s
                t=t+1
            p.append(t)
        s=s+1
    if n!=1:
        a.append(n)
        p.append(1)
    type=0
    # for i in range(len(a)):
    #    print(a[i],p[i])
    if (len(a)==1):
        v=1
        for i in range(p[0]):
            v=v*a[0]
            print(v,end=' ')
        print()
        print(0)
    else:
        type=0
        if p[0]==1 and p[1]==1 and len(a)==2:
            print(a[0],a[1],a[0]*a[1])
            print(1)
        else:
            if (len(a)==2):
                construct1(a,p)
            else:
                construct2(a,p)