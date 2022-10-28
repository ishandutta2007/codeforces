I=input
n,q=map(int,I().split())
s=I()
c=s.count('abc')
v=[*s]
for _ in[0]*q:
	a,b=I().split();a=int(a)-1;d=-1
	for x in[0,0]:
		if'abc'in''.join(v[max(a-2,0):a+3]):c+=d
		v[a]=b;d=-d
	print(c)