r=lambda:map(int,raw_input().split())
n,c=r()
a=[r()for i in range(n)]
def F(x):
	l,r=0,1<<60
	while l<r-1:
		m=l+r>>1
		s=0
		for i in range(n):
			s+=1+a[i][0]*m/a[i][1]
		if s<x:
			l=m
		else:
		 	r=m
	return r
z=F(c+1)-F(c)
print [z,-1][z>10**9]