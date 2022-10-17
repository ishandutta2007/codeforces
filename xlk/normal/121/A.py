l,r=map(int,raw_input().split())
a=[]
def F(x):
	a.append(x)
	if x>r*10:
		return
	F(10*x+4)
	F(10*x+7)
F(0)
a=sorted(a)
def G(x):
	z=0
	for i in range(1,len(a)):
		z+=a[i]*(min(a[i],x)-min(a[i-1],x))
	return z
print G(r)-G(l-1)