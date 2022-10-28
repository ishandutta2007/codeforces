# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, x = I()
	a = sorted(I())
	partial = [0]
	for guy in a:
		partial.append(partial[-1] + guy)
	packs = 0
	for i in range(1, n + 1):
		packs += max(0, (x - partial[i]) // i + 1)
	print(packs)