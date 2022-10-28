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
		grid.append([*input().strip()])
	for i in range(m):
		fallto = n - 1
		for j in range(n - 1, -1, -1):
			if grid[j][i] == "o":
				fallto = j - 1
			elif grid[j][i] == "*":
				grid[j][i] = '.'
				grid[fallto][i] = "*"
				fallto -= 1
	for g in grid:
		print(''.join(g))