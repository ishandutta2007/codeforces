import sys
inpu = sys.stdin.readline
prin = sys.stdout.write
import math

t = int(inpu())
for _ in range(t):
	n, k = map(int, inpu().split())
	a = list(map(int, inpu().split()))
	a.sort()
	score = sum(a[:n - 2 * k])
	left = a[- 2 * k:]
	for i in range(k):
		score += left[i]//left[i + k]
	print(score)