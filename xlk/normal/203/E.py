n,d,s=map(int,raw_input().split())
c0=[]
c1=[]
v=0
for i in range(n):
	c,f,l=map(int,raw_input().split())
	v+=c
	if l>=d:
		c0+=[f]
		if c:
			c1+=[f]
c0.sort()
y=z=0
if c1!=[]:
	u=min(c1)
	c0.remove(u)
	v+=1
	for i in c0:
		if u<=s:
			z,y=max([z,y],[min(v,n),-u])
		else:
			break
		u+=i
		v+=1
	if u<=s:
		z,y=max([z,y],[min(v,n),-u])
v=u=0
for i in c0:
	if u+i>s:
		break
	u+=i
	v+=1
z,y=max([z,y],[v,-u])
print z,-y