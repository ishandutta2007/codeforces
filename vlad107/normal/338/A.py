BASE=1000000009
def pow(x,y):
	res=1
	while (y):
		if (y%2==1):res=res*x%BASE
		x=x*x%BASE
		y/=2
	return res%BASE
n,m,k=map(long,raw_input().split())
x=((n/k)*(k-1))+n%k;
if (x>=m):
	print m
	exit(0)
t=m-x
u=pow(2,t)
u=(2*(u-1)*k+m-t*k)%BASE
print u