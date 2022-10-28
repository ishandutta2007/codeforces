# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	l1, r1, l2, r2 = I()
	if r1 >= l2 and r2 >= l1:
		print(max(l1, l2))
	else:
		print(l1 + l2)