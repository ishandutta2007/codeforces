from fractions import* 
n,m=map(int,raw_input().split())
a=map(lambda x:int(x)-1,raw_input().split())
g=reduce(gcd,a)
while g%2==0:g/=2
def F(x):
	z=0
	while x<m:
		z+=m-x
		x*=2
	return z
a=[]
for i in range(1,int(g**.5)+1):
	if g%i==0:
		a+=[i]
		if i*i<g:
			a+=[g/i]
print sum(map(F,a))