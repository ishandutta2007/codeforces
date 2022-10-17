n,m=map(int,raw_input().split())
f=range(n+1)
c=[1]*(n+1)
def F(x):
	if f[x]!=x:
		f[x]=F(f[x])
	return f[x];
z=0;
for i in range(m):
	x,y=map(int,raw_input().split())
	if F(x)==F(y) and c[F(x)]%2==1:
		z+=1
	else:
		c[F(x)]+=c[F(y)]
		f[F(y)]=F(x)
print z+(n-z)%2