x,y=map(int,raw_input().split())
n=input()%6+5
z=0
for i in range(n):
	z=(y-x+1000000007)%1000000007
	x=y
	y=z
print x