import math
n,s=map(int,input().split())
v=list(map(int,input().split()))
x=sum(v)
if s>x:
    print(-1)
else:
    a=min(v)
    if s<x-n*a:
        print(a)
    else:
        b=x-n*a
        c=s-b
        print(a-math.ceil(c/n))