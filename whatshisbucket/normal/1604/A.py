import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	big = 0
	for i in range(n):
		big = max(big, a[i] - i - 1)
	print(big)