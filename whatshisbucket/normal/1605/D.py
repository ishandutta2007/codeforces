p,r=input,range
for _ in r(int(p())):
	n=int(p());h=[set()for i in r(n)]
	if n==1:print(1);continue
	for i in r(n-1):u,v=map(int,p().split());h[u-1].add(v-1);h[v-1].add(u-1)
	c,s,g,i=[len(h[i])for i in r(n)],[0]*n,[0],1
	while 2**i-1<n:g.append(2**i-1);i+=1
	g.append(n);l=[i for i in r(n)if c[i]==1]
	while l!=[]:
		b=[]
		for v in l:
			c[v],e=0,set()
			for u in h[v]:
				if c[u]>0:
					c[u]-=1
					if c[u]==1:b.append(u)
				elif s[u]!=0:e.add(len(bin(s[u]))-2)
			for i in r(len(g)-1,0,-1):
				if i not in e and g[i]>=2**(i-1):s[v]=g[i];g[i]-=1;break
		l=b
	print(' '.join([str(c)for c in s]))