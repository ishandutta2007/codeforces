# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	loops = k // (n - 1)
	extra = k % (n - 1)
	if extra == 0:
		extra -= 1
	print(loops * n + extra)