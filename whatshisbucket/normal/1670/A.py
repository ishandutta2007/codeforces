# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	negs = 0
	for guy in a:
		if guy < 0:
			negs += 1
	b = []
	for i in range(n):
		if i < negs:
			b.append(-abs(a[i]))
		else:
			b.append(abs(a[i]))
	print('YES' if b == sorted(b) else 'NO')