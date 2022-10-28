# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, a, b = I()
	x = [0] + I()
	suffixes = [0]
	for i in range(n - 1, -1, -1):
		move = x[i + 1] - x[i]
		tot = suffixes[-1] + len(suffixes) * move * b
		suffixes.append(tot)
	suffixes = suffixes[::-1]
	best = float('inf')
	for i in range(n + 1):
		best = min(best, x[i] * (b + a) + suffixes[i])
	print(best)