# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	first = None
	last = None
	for i in range(n - 1):
		if a[i] == a[i + 1]:
			last = i
			if first is None:
				first = i
	if first is None:
		print(0)
	else:
		x = last - first - 1
		if x <= 0:
			x += 1
		print(x)