# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	b = I()
	tot = 0
	for i in range(n - 1):
		w, x, y, z = a[i], b[i], a[i + 1], b[i + 1]
		tot += min(abs(w - y) + abs(x - z), abs(w - z) + abs(x - y))
	print(tot)