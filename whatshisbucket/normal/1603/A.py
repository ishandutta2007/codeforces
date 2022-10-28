x=input
t=int(x())
while t>0:
	t-=1
	n=int(x())
	a=list(map(int,x().split()))
	y=min(n,22)
	for i in range(y+1):
		if i==y:
			print("YES")
		else:
			j=i+2
			while a[i]%j==0 and j>1:
				j-=1
			if j==1:
				print("NO")
				break