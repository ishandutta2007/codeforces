# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	w = I()
	tot = sum(w)
	best = 0
	a = 0
	b = n
	atot = 0
	btot = 0
	while a <= b:
		if atot == btot:
			best = a + n - b
		if atot <= btot:
			atot += w[a]
			a += 1
		else:
			b -= 1
			btot += w[b]
	print(best)