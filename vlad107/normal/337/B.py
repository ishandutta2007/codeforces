def g(x,y):
	if (x*y==0):return x+y
	return g(x,y%x) if y>x else g(x%y,y)
a,b,c,d=map(int,raw_input().split())
p,q=[[a*d-b*c,a*d],[b*c-a*d,b*c]][a*d<=b*c]
print str(p/g(p,q))+"/"+str(q/g(p,q))