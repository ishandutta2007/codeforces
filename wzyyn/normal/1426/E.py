# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

n=int(input())
a=array.array('i',map(int,input().split()))
b=array.array('i',map(int,input().split()))
ans1=max(a[0]-b[0]-b[2],0)+max(a[1]-b[1]-b[0],0)+max(a[2]-b[2]-b[1],0)
ans2=min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0])
print(ans1,ans2)