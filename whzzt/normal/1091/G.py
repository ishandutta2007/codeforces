from random import randint
from sys import stdout
import random

N=int(input())
random.seed(N%998244353)
M=1
cnt=0
while M*2<=N:
    M<<=1
    cnt+=1

def rnd():
    u=0
    for i in range(cnt):
        u=u*2+randint(0,1)
    return u

def gcd(x,y):
    r=0
    while (x&1)==0 and (y&1)==0:
        x>>=1
        y>>=1
        r+=1
    while (x&1)==0:
        x>>=1
    while (y&1)==0:
        y>>=1
    while x>0:
        if x<y:
            x,y=y,x
        x-=y
        if x>0:
            while (x&1)==0:
                x>>=1
    return y<<r

v=[]
for T in range(15):
    x=rnd()
    u=x*x%N
    print('sqrt',u)
    stdout.flush()
    y=int(input())
    if y!=-1 and x!=y:
        if x<y:
            x,y=y,x
        v.append([x,y])

def solve(m):
    global N
    p=[]
    for it in v:
        g=gcd(it[0]-it[1],m)
        if g!=1 and g!=m:
            q=solve(g)
            for t in q:
                p.append(t)
            q=solve(m//g)
            for t in q:
                p.append(t)
            return p
    return [m]

w=solve(N)
w.sort()
ans='! '+str(len(w))
for i in w:
    ans+=' '+str(i)
print(ans)