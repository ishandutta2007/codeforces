a,b,m=map(float,raw_input().split())
x,y,z=map(float,raw_input().split())
m/=-y
x=(x*m+a*.5)%(2*a);
z=z*m%(2*b)
x=min(x,2*a-x)
z=min(z,2*b-z)
print x,z