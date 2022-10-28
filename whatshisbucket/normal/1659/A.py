# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, r, b = I()
	x = r // (b + 1)
	y = r % (b + 1)
	out = y * ((x + 1) * 'R' + 'B') + (b + 1 - y) * (x * 'R' + 'B')
	print(out[:-1])