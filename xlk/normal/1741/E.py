t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	f = [0 for i in range(n + 1)]
	f[0] = 1
	for i in range(n):
		if i - a[i] >= 0 and f[i - a[i]]:
			f[i + 1] = 1
		if f[i] and i + a[i] + 1 <= n:
			f[i + a[i] + 1] = 1
	print(['NO', 'YES'][f[n]])