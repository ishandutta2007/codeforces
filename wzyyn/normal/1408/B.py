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
    
    def solve1():
        if a[0]==a[n-1]:
            print(1)
        else:
            print(-1)
        
    def solve2():
        sum=0
        # if a[0]!=0:
        # sum=sum+1
        for i in range(1,n):
            if a[i]!=a[i-1]:
                sum=sum+1
        print(max(1,(sum+k-2)//(k-1)))

    if (k==1):
        solve1()
    else:
        solve2()