# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	a = I()
	if k < n:
		partial = [0]
		for guy in a:
			partial.append(partial[-1] + guy)
		best = 0
		for i in range(n - k + 1):
			best = max(best, partial[i + k] - partial[i])
		print(best + k * (k - 1) // 2)
	else:
		s = sum(a)
		print(s + (k - 1) * n - n * (n - 1) // 2)