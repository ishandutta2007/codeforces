# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, m = I()
	s = input()
	covered = [0] * m
	columns = [0]
	curr = 0
	for i in range(n * m):
		if s[i] == '1':
			if not covered[i % m]:
				covered[i % m] = 1
				curr += 1
		columns.append(curr)
	goods = []
	bads = []
	length = m
	prev = None
	for i in range(n * m):
		if s[i] == '1':
			if length >= m:
				goods.append(i)
				if prev is not None:
					bads.append(prev)
			length = 0
			prev = i
		else:
			length += 1
	if prev is not None:
		bads.append(prev)
	changes = [0] * (n * m)
	ginds = [0] * m
	binds = [0] * m
	gind = 0
	bind = 0
	for i in range(n * m):
		if gind < len(goods) and i == goods[gind]:
			gind += 1
			ginds[i % m] += 1
		changes[i] = ginds[i % m] - binds[i % m]
		if bind < len(bads) and i == bads[bind]:
			bind += 1
			binds[i % m] += 1
	rows = [0]
	for guy in changes:
		rows.append(rows[-1] + guy)
	x = [rows[i] + columns[i] for i in range(1, n * m + 1)]
	print(*x)