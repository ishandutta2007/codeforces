# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, x = I()
	a = I()
	curr = sum(abs(a[i + 1] - a[i]) for i in range(n - 1))
	add1 = min(2 * (x - max(a)), x - a[-1], x - a[0])
	add2 = min(2 * (min(a) - 1), a[0] - 1, a[-1] - 1)
	print(curr + max(add1, 0) + max(add2, 0))