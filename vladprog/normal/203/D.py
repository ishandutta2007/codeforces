R=lambda:map(int,input().split())
a,b,m=R()
x,y,z=R()
t=-m/y
x0=(a/2+t*x)%(2*a)
if x0>a:
    x0=2*a-x0
z0=(t*z)%(2*b)
if z0>b:
    z0=2*b-z0
print(x0,z0)