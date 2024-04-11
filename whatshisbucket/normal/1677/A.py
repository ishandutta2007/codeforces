# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	p = I()
	cpairs = []
	for i in range(n):
		stuff = [0]
		for j in range(i):
			if p[i] > p[j]:
				stuff.append(stuff[-1] + 1)
			else:
				stuff.append(stuff[-1])
		cpairs.append(stuff)
	ttot = 0
	for b in range(1, n):
		tot = 0
		for d in range(b + 2, n):
			tot += cpairs[d - 1][b]
			if p[b] > p[d]:
				ttot += tot
				#print(b, d, tot)
	print(ttot)