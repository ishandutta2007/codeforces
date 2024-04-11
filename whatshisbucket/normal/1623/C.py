I=input
for _ in[0]*int(I()):
	n,h,s,b=int(I()),[*map(int,I().split())],1,1<<30
	while b-s>1:
		m,u,i=(b+s)//2,h[:],n
		while i:
			i-=1
			if u[i]<m:b=m;break
			x=[0,min(h[i],u[i]-m)//3][i>1];u[i-1]+=x;u[i-2]+=2*x
		else:s=m
	print(s)