# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	a = I()
	b = [(i, a[i] + i) for i in range(n)]
	b.sort(reverse = True, key = lambda x: x[1])
	jump = {guy[0] for guy in b[:k]}
	cost = 0
	jumped = 0
	for i in range(n):
		if i in jump:
			jumped += 1
		else:
			cost += a[i] + jumped
	print(cost)