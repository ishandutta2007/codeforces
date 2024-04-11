I=lambda:[*map(int,input().split())]
n,m,q=I()
a,b,q=I(),I(),I()
t=sorted([(i,1)for i in a]+[(i,0)for i in b])
o=sum(a)
v=[(0,o)]
s={}
e={}
p=[0]
c=[]
for i in range(n+m):y=t[i][0];p.append(p[-1]+y);s[i]=e[i+1]=(i,i+1,t[i][1]);c.append((y-t[i-1][0],i))
c=sorted(c[1:])
for x,i in c:f=e[i];l=s[i];b=f[2]+l[2];a=l[1];o+=p[a-l[2]]-p[a-b]+p[i-f[2]]-p[i];del s[i];del e[i];s[f[0]]=e[a]=(f[0],a,b);v.append((x,o))
for g in q:
	s=0;e=m+n
	while e-s>1:
		d=(s+e)//2
		if v[d][0]>g:e=d
		else:s=d
	print(v[s][1])