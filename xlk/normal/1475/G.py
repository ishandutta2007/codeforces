for _ in range(int(input())):
	n,m=int(input()),200001
	f,c=[0]*m,[0]*m
	for i in map(int,input().split()):
		c[i]+=1
	for i in range(1,m):
		f[i]+=c[i]
		for j in range(i,m,i):
			f[j]=max(f[j],f[i])
	print(n-max(f))