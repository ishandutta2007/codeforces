r,m,f,d=range,998244353,[1],[1];n,x=map(int,input().split())
for i in r(1,n+1):f.append(f[-1]*i%m);d.append(d[-1]*pow(i,m-2,m)%m)
n+=1;x+=1;t=[[0]*(n)for i in r(x+n)]
for j in r(1,n):
	for k in r(j+1):t[j+x][k]=(pow(j-1,j-k,m)*f[j]*d[k]*d[j-k])%m
for i in r(x):
	t[i][0]=1
	for j in r(2,n):t[i][j]=pow(i,j,m)if j>i else sum(t[i-j+1][k]*t[j+x][k]for k in r(j+1))%m
print(t[x-1][-1])