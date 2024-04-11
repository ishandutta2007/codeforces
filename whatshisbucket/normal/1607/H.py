u=input
for _ in range(int(u())):
	u();n,v=int(u()),0;o=[0]*n;y=o[:]
	for i in range(n):a,b,m=map(int,u().split());y[i]=(a+b-m,a,b,m,i)
	y.sort()
	for t,a,b,m,i in y:
		if v==0 or t>s or max(0,a-m)>r:r,v,s=min(t,a),v+1,t
		o[i]=str(a-r)+' '+str(m+r-a)
	print(v,'\n','\n'.join(o))