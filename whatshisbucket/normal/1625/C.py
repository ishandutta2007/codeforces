I=lambda:[*map(int,input().split())]
n,l,k=I()
r=range
m=min
d=I()
e=[d[i+1]-d[i]for i in r(n-1)]+[l-d[-1]]
a=I()
p=[[1e9]*n for i in r(n)]
p[0][0]=a[0]*e[0]
for i in r(1,n):
	w=[[1e9]*n for i in r(n)]
	for x in r(m(i,k)+1):
		w[x][i]=m(p[x])+a[i]*e[i]
		for j in r(i-x,i):w[x][j]=p[x-1][j]+a[j]*e[i]
	p=w
print(m(m(g)for g in p))