# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	if n == 1:
		if a[0] > 1:
			print('NO')
		else:
			print('YES')
		continue
	x = max(a)
	a.remove(x)
	y = max(a)
	if x - y > 1:
		print('NO')
	else:
		print('YES')