from collections import*
for t in range(int(input())):
	z=s=int(input())
	c=0
	for x,y in sorted(Counter(Counter(input().split()).values()).items())[::-1]:
		c+=y
		z=min(z,s-c*x)
	print(z)