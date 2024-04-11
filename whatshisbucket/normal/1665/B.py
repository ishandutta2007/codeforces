# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	a.sort()
	curr = 1000000001
	run = 0
	big = 0
	for guy in a:
		if guy != curr:
			run = 1
			curr = guy
		else:
			run += 1
		big = max(big, run)
	moves = n - big
	ratio = (n - 1) // big
	if ratio != 0:
		moves += len(bin(ratio)) - 2
	print(moves)