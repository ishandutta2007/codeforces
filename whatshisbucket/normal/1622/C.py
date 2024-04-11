I=lambda:[*map(int,input().split())]
for _ in[0]*I()[0]:
	n,k=I();a=sorted(I());k+=a[0];b=1<<50
	for i in range(n):k-=a[i];b=min(max(0,a[0]-k//(n-i))+n-i-1,b)
	print(b)