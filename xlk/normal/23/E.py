from fractions import *
def F(u,v):
	global e
	e[u].remove(v)
	n,x,y,z=len(e[u]),1,1,1
	f=[1]+[0]*n
	for i in e[u]:
		a,b,c=F(i,u)
		x*=a
		y=max(y,Fraction(b)/a)
		z*=a
		for j in range(n,0,-1):
			f[j]=max(f[j-1]*c,f[j]*a)
		f[0]*=a
	x,y=int(x*y),0
	for i in range(n+1):
		x=max(x,f[i]*(i+1))
		y=max(y,f[i]*(i+2))
	return x,y,z
n=input()
e=[[]for i in range(n+1)];
for i in range(n-1):
	x,y=map(int,raw_input().split())
	e[x]+=[y]
	e[y]+=[x]
e[1]+=[0]
print F(1,0)[0]