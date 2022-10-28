import sys
r=range
I=lambda:[*map(int,sys.stdin.readline().split())]
n,q=I()
p=[g-1 for g in I()]
v=[0]*n
for i in r(n):v[p[i]]=i
Q=int(n**0.5)
P=[]
for i in r(n):
	for j in r(Q):i=p[i]
	P.append(i)
for _ in r(q):
	a,b,c=I();b-=1
	if a>1:
		for i in r(c//Q):b=P[b]
		for i in r(c%Q):b=p[b]
		print(b+1)
	else:
		c-=1;d,e=p[b],p[c];p[b],p[c]=e,d;v[d],v[e]=c,b
		for i in r(Q - 1):b,c=v[b],v[c]
		for j in r(Q):P[b],P[c]=e,d;b,c,e,d=p[b],p[c],p[e],p[d]