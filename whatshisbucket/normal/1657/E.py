n,k=map(int,input().split())
r=range
M=998244353
k+=1
F=[[1]]
for i in r(1,n):F.append([1]+[(F[-1][j]+F[-1][j+1])%M for j in r(i-1)]+[1])
d=[0]*n
d[0]=1
for i in r(1,k):
	for j in r(n-1,0,-1):
		x=0
		for l in r(0,j+1):D=j-l;x+=d[l]*F[n-1-l][D]*pow(k-i,D*l+D*(D-1)//2,M)%M
		d[j]=x%M
print(d[-1])