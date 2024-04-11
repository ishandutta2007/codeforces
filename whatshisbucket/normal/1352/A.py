# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	out = []
	for guy in [10, 100, 1000, 10000, 100000]:
		if n % guy != 0:
			out.append(n % guy)
			n -= n % guy
	print(len(out))
	print(*out)