# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def invs(a):
	l = len(a)
	if l == 1:
		return 0
	x = a[:l // 2]
	y = a[l // 2:]
	tot = invs(x) + invs(y)
	x.sort()
	y.sort()
	yind = 0
	for guy in x:
		while yind < len(y) and y[yind] <= guy:
			yind += 1
		tot += yind
	return tot

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	print(invs(a))