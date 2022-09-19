n,k=map(int,input().split())
import math
v=math.pi
v/=n
a=math.sin(v)
t=a/(1-a)
print(k*t)