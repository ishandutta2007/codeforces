# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

M = 998244353
facs = [1]
for i in range(1000):
	facs.append(facs[-1] * (i + 1) % M)

t, = I()
for _ in range(t):
	n, = I()
	if n % 2 == 0:
		print(facs[n // 2] ** 2 % M)
	else:
		print(0)