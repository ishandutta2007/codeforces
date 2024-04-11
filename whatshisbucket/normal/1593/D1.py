import math
t=int(input())
for _ in range(t):
	n=int(input())
	l = list(map(int,input().split()))
	l.sort()
	if l[0] == l[-1]:
		print(-1)
	else:
		gcd = l[1]-l[0]
		for i in range(1,n-1):
			gcd = math.gcd(gcd,l[i+1]-l[i])
		print(gcd)