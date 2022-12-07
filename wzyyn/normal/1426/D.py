# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

n=int(input())
a=array.array('i',map(int,input().split()))
sum,ans=0,0
mp=dict()
mp[0]=0
for i in range(n):
    sum=sum+a[i]
    if sum in mp:
        mp=dict()
        mp[sum-a[i]]=1
        ans=ans+1
        # print(i)
    mp[sum]=1
print(ans)