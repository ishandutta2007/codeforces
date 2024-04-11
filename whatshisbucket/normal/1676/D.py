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
		grid.append(I())
	main = {}
	other = {}
	for i in range(n):
		for j in range(m):
			if i - j in main:
				main[i - j] += grid[i][j]
			else:
				main[i - j] = grid[i][j]
			if i + j in other:
				other[i + j] += grid[i][j]
			else:
				other[i + j] = grid[i][j]
	best = 0
	for i in range(n):
		for j in range(m):
			best = max(best, main[i - j] + other[i + j] - grid[i][j])
	print(best)