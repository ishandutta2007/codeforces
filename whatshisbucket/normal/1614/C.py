I=lambda:[*map(int,input().split())]
M=10**9+7
for _ in[0]*I()[0]:
	n,m=I();o=0
	for i in range(m):o|=I()[2]
	print(o*2**(n-1)%M)