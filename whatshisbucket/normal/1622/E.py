I=lambda:[*map(int,input().split())]
r=range;s=sum
for _ in[0]*I()[0]:
	n,m=I();e=I();M=[[*map(int,[*input().strip()])]for i in r(n)];o=[bin(i).count('1')for i in r(1<<n)];q=[s(1<<i for i in r(n)if M[i][j])for j in r(m)];b=-1
	for i in r(1<<n):
		c=[0]*(n+1);v=[0]*m;d=c[:];P=v[:]
		for j in r(m):v[j]=o[i^q[j]];c[v[j]]+=1
		for j in r(n):d[j+1]=d[j]+c[j]
		for j in r(m):d[v[j]]+=1;P[j]=d[v[j]]
		T=2*s(e[j]for j in r(n) if(i>>j)&1)-s(e)+s((o[q[j]]-2*o[i&q[j]])*P[j]for j in r(m))
		if T>b:b,p=T,P
	print(*p)