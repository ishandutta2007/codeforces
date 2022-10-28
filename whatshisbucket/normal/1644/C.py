import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
import random

t, = I()
for _ in range(t):
	n, x = I()
	a = I()
	partial = [0]
	for i in range(n):
		partial.append(partial[-1] + a[i])
	big = [-float('inf')] * (n + 1)
	big[0] = 0
	for i in range(n):
		for j in range(i + 1, n + 1):
			big[j - i] = max(big[j - i], partial[j] - partial[i])
	best = [-float('inf')] * (n + 1)
	for i in range(n + 1):
		good = -float('inf')
		for j in range(n + 1):
			good = max(good, big[j] + x * min(j, i))
		best[i] = good
	print(*best)