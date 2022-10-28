# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]


t, = I()
for _ in range(t):
	n, = I()
	a = I()
	crossings = 0
	for i in range(n):
		for j in range(i + 1, n):
			if a[j] <= a[i]:
				crossings += 1
	print(crossings)