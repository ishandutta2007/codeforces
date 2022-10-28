# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	c = I()
	if c.count(1) != 1:
		print('NO')
	else:
		x = c.index(1)
		x -= n
		for i in range(n):
			if c[x + 1] > c[x] + 1:
				print('NO')
				break
			x += 1
		else:
			print('YES')