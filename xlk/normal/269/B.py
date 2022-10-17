from bisect import *
n=int(raw_input().split()[0])
f=[10**10]*5020
for i in range(n):
    x=int(raw_input().split()[0])
    f[bisect_right(f,x)]=x
print n-bisect_left(f,10**10)