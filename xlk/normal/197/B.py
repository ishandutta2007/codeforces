def gcd(x,y):
	return gcd(y,x%y)if y else x
n,m=map(int,raw_input().split())
a=int(raw_input().split()[0])
b=int(raw_input().split()[0])
if n>m:
	print "Infinity"if a*b>0 else"-Infinity"
elif n<m:
	print "0/1"
else:
	a,b=a/gcd(a,b),b/gcd(a,b)
	if b<0:
		a,b=-a,-b
	print "%d/%d"%(a,b)