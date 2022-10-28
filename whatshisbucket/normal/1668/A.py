# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, m = I()
	if n > m:
		n, m = m, n
	if n == 1 and m >= 3:
		print(-1)
	else:
		steps = 2 * m - 2
		if (n - m) % 2:
			steps -= 1
		print(steps)