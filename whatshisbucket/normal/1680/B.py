# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, m = I()
	grid = []
	for i in range(n):
		grid.append(input())
	seen = False
	x = None
	for i in range(n):
		if 'R' in grid[i]:
			ind = grid[i].index('R')
			if not seen:
				seen = True
				x = ind
			else:
				if ind < x:
					print('NO')
					break
	else:
		print('YES')