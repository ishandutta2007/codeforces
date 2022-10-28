import sys
I=sys.stdin.readline
def f(s, e, l):
	while s<=e:
		if l[s]:return s
		s+=2
for _ in[0]*int(I()):
	I();n,m=map(int,I().split());s=[I()for i in range(n)];n-=1;d=[0]*(n+m)
	for i in range(n+m):
		r,c,e=min(i,n),max(0,i-n),min(i,m-1)
		while r>=0 and c<m:
			if s[r][c]>'0':
				p=f(c-r,e,d)
				if p==None:d[c-r]=1;break
				else:d[p],d[c-r],c,r=0,1,(i+p)//2,(i-p)//2
			r-=1;c+=1
	print(sum(d))