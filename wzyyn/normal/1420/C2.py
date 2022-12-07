# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

input=__import__('sys').stdin.readline

def solve():
    n,Q=map(int,input().split())
    a=array.array('i',map(int,input().split()))
    
    def jud(x):
        if x<0 or x>=n:
            return 0
        p,s=0,0
        if x!=0:
            p=a[x-1]
        if x+1!=n:
            s=a[x+1]
        if p<a[x] and s<=a[x]:
            return a[x]
        if p>a[x] and s>=a[x]:
            return -a[x]
        return 0
    
    ans=0
    for i in range(n):
        ans=ans+jud(i)
    print(ans)
    
    for i in range(Q):
        x,y=map(int,input().split())
        kx,ky=a[x-1],a[y-1]
        
        ans=ans-jud(x-2)-jud(x-1)-jud(x)
        a[x-1]=ky
        ans=ans+jud(x-2)+jud(x-1)+jud(x)
        
        ans=ans-jud(y-2)-jud(y-1)-jud(y)
        a[y-1]=kx
        ans=ans+jud(y-2)+jud(y-1)+jud(y)
        
        print(ans)

T=int(input())

for Tid in range(T):
    solve()