import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	a, b = I()
	best = float('inf')
	for i in range(a, b):
		for j in range(19, -1, -1):
			if (i >> j & 1) and not (b >> j & 1):
				m = 1 << j
				cost = m - b % m + i % m
				#print(i, j, cost)
				break
		else:
			cost = 0
		best = min(best, cost + i - a)
	best = min(best + 1, b - a)
	print(best)