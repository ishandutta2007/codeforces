# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

mo=1000000007

n=int(input())
a=array.array('i',[0 for i in range(4)])
s=input()
a[0]=1
for i in range(n):
    b=array.array('i',[0 for i in range(4)])
    key=1
    if s[i]=='?':
        key=3
    for j in range(4):
        b[j]=a[j]*key%mo
    if s[i]=='?' or s[i]=='a':
        b[1]=(b[1]+a[0])%mo
    if s[i]=='?' or s[i]=='b':
        b[2]=(b[2]+a[1])%mo
    if s[i]=='?' or s[i]=='c':
        b[3]=(b[3]+a[2])%mo
    a=b

print(a[3])