n,m=map(int,raw_input().split())
z=0
for i in range(n):
	t,T,x,c=map(int,raw_input().split())
	if t>=T:
		z+=c+x*m
	else:
		z+=min(c+x*m,m/(t-T)*-c)
print z