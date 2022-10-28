import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n, a, b = map(int, inpu().split())
	if a > n // 2 + 1 or b < n//2 or max(a, b) == n // 2 or min(a, b) == n // 2 + 1:
		print(-1)
	else:
		perm = [n - i for i in range(n)]
		if a < b:
			perm[n - a], perm[n - b] = perm[n - b], perm[n - a]
		print(' '.join(str(guy) for guy in perm))