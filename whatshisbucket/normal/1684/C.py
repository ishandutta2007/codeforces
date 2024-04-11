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
	bad = False
	pair = None
	nones = []
	j = 0
	for row in grid:
		x = sorted(row)
		diffs = []
		for i in range(m):
			if x[i] != row[i]:
				diffs.append(i)
		if len(diffs) >= 3:
			bad = True
			break
		elif len(diffs) == 2:
			if pair is not None and (diffs[0] != pair[0] or diffs[1] != pair[1]):
				bad = True
				break
			elif pair is None:
				pair = diffs
				for i in nones:
					if grid[i][diffs[0]] != grid[i][diffs[1]]:
						bad = True
						break
				if bad:
					break
		elif len(diffs) == 0:
			nones.append(j)
			if pair is not None:
				if row[pair[0]] != row[pair[1]]:
					bad = True
					break
		j += 1
	if not bad:
		if pair is not None:
			print(pair[0] + 1, pair[1] + 1)
		else:
			print(1, 1)
	else:
		print(-1)