# import numpy as npy
# idx=sorted(idx,key=functools.cmp_to_key(cmpx))
import bisect
import array
import functools
import math

input=__import__('sys').stdin.readline

mo=998244353
fac=array.array('i',[0 for i in range(300005)])
inv=array.array('i',[0 for i in range(300005)])

def init():
    fac[0]=inv[0]=inv[1]=1
    for i in range(2,300005):
        inv[i]=inv[mo%i]*(mo-mo//i)%mo
    for i in range(1,300005):
        fac[i]=fac[i-1]*i%mo
        inv[i]=inv[i-1]*inv[i]%mo
    
def C(n,m):
    if n<0 or m<0 or m>n:
        return 0
    return fac[n]*inv[m]*inv[n-m]%mo

n,k=map(int,input().split())
a=array.array('i',[0 for i in range(n)])
b=array.array('i',[0 for i in range(n)])

init()
for i in range(n):
    a[i],b[i]=map(int,input().split())
a=sorted(a)
b=sorted(b)

ans=0
p,s=0,0

for i in range(n):
    while b[p]<a[i]:
        p=p+1
        s=s-1
    # print(i,a[i],s)
    ans=ans+C(s,k-1)
    s=s+1

print(ans%mo)