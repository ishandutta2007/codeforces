import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	b = list(map(int, inpu().split()))
	a.sort()
	b.sort()
	good = True
	for i in range(n):
		if b[i] - a[i] not in [0, 1]:
			good = False
	if good:
		print("YES")
	else:
		print("NO")