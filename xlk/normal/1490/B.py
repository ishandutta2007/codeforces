for t in range(int(input())):
	n=int(input())
	c=[-n//3]*3
	z=0
	for i in map(int,input().split()):
		c[i%3]+=1
	for i in range(-3,2):
		if c[i]>0:
			z+=c[i]
			c[i+1]+=c[i]
			c[i]=0
	print(z)