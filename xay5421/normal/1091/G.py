import sys
import math
import random
gcd=math.gcd
rng=random.randint

ans=[]

def sol():
	global n
	print(n)
	x=rng(1,10**18)%n
	g=gcd(x,n)
	if g!=1:
		ans.append(g)
	else:
		print("sqrt "+str(x*x%n))
		sys.stdout.flush()
		t=int(input())
		if t==x or t==n-x:
			return
		g=gcd(x+t,n)
		ans.append(g)

n=int(input())
res=[n]
for i in range(30):
	if n>1:
		sol()
for i in ans:
	tmp=[]
	for j in res:
		x=gcd(i,j)
		if x!=1 and x!=j:
			tmp.append(x)
			tmp.append(j//x)
		else:
			tmp.append(j)
	res=tmp
			
res.sort()
print("! "+str(len(res)),end=' ')
for i in res:
	print(i,end=' ')