import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n, k = map(int,inpu().split())
	a = list(map(int, inpu().split()))
	bigs = [10**(a[i+1]-a[i])-1 for i in range(n-1)]
	needed = k+1
	used = [0]*n
	i = 0
	while needed >= 0:
		if i == n-1:
			used[-1] = needed
			break
		elif bigs[i] <= needed:
			used[i] = bigs[i]
			needed -= bigs[i]
		else:
			used[i] = needed
			break
		i += 1
	tot = 0
	for i in range(n):
		tot += used[i]*10**a[i]
	print(tot)