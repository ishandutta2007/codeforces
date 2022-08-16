for _ in range(int(input())):
	n = int(input())
	a = list(map(int,input().split()))
	ans = "YES"
	cur = 0
	for i in range(n-1):
		cur += a[i]
		if cur <= 0:
			ans = "NO"
	cur = 0	
	for i in range(n-1,0,-1):
		cur += a[i]
		if cur <= 0:
			ans = "NO"
	print(ans)