n=long(input())
a,b,c=[[0],[2],[13]],[],[]
for i in range(1,600):
	if i>2:a+=[[12*x for x in a[i-2]]+[12*a[i-1][len(a[i-1])-1]-11]]
	if (n in a[i]):b,c=b+[i],c+a[i]
b,c,n=sorted(b),sorted(list(set(c)-{n})),min(len(b),1000)
m=min(len(c),1000)
if n==0:
	print "NO"
else:print "YES\n",n,"\n","\n".join(map(str,[b[i] for i in range(n)])),"\n",m,"\n","\n".join(map(str,[c[i] for i in range(m)]))