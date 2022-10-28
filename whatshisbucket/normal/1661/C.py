# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	h = I()
	big = max(h)
	h = [big - guy - 1 for guy in h]
	best = float('inf')
	for i in range(5):
		ones = 0
		twos = 0
		for i in range(n):
			h[i] += 1
		for guy in h:
			ones += guy % 2
			twos += guy // 2
		if ones > twos:
			best = min(best, 2 * ones - 1)
			continue
		x = (twos - ones) // 3
		twos -= x
		ones += 2 * x
		if twos - ones <= 1:
			best = min(best, 2 * twos)
		else:
			best = min(best, 2 * twos - 1)
	print(best)