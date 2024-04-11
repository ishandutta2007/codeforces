import sys
I=sys.stdin.readline
r=range
def C(k,v,l,h,o,n):
	t,a=0,[]
	for c in k[v]:a.append(o[c])
	if a and min(a)<0:o[v]=min(a)+1
	elif n in a:o[v]=n
	else:o[v]=sum(a)+a.count(0)
	if k[v]==[]:o[v]=n
	if v in l:o[v]=-(h//2)
for _ in r(int(I())):
	I();n,f=int(I().split()[0]),{*map(int,I().split())};g={i+1:[]for i in r(n)}
	for i in r(n-1):
		u,v=map(int, I().split());g[u].append(v);g[v].append(u)
	l,p,k,H,i,o=[1],{1:0},{},[],0,{}
	while l:
		for y in l:H.append((i,y))
		i+=1;L=[]
		for y in l:
			c=[]
			for v in g[y]:
				if v!=p[y]:c.append(v);p[v]=y
			k[y]=c;L+=c
		l=L
	for h,v in H[::-1]:C(k,v,f,h,o,n)
	print(('NO','YES')[o[1]>=n])