import sys
u=sys.stdin.readline
for _ in range(int(u())):
	p=[list(map(int,u().split()))for i in range(int(u()))];s,b=0,len(p)
	while b>s:
		c,i=(s+b+1)//2,0
		for j in range(len(p)):
			if p[j][0]>=c-i-1 and p[j][1]>=i:i+=1
		if i>=c:s=c
		else:b=c-1
	print(s)