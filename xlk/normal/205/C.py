def F(x):
	l=len(str(x))
	z=0
	if l==1:
		return x
	elif l==2:
		return x/11+9
	else:
		z=18
	for i in range(3,l):
		z+=9*10**(i-2)
	f=int(str(x)[0])
	z+=(f-1)*10**(l-2)
	g=int(str(x)[1:])
	g/=10
	z+=g
	h=int(str(f)+str(x)[1:l-1]+str(f))
	if h<=x:
		z+=1
	return z
x,y=map(int,raw_input().split())
print F(y)-F(x-1)