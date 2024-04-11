# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	s1 = input()
	s2 = input()
	cols = []
	for i in range(n):
		if s1[i] == '*' and s2[i] == '*':
			cols.append((i, 2))
		elif s1[i] == '*':
			cols.append((i, 0))
		elif s2[i] == '*':
			cols.append((i, 1))
	tot = cols[-1][0] - cols[0][0]
	prev = 2
	for i in range(len(cols)):
		if cols[i][1] == 2:
			tot += 1
			prev = 2
		if i > 0 and cols[i][1] + cols[i - 1][1] == 1:
			tot += 1
		if i > 0 and i < len(cols) - 1 and cols[i][1] == 1 - prev and cols[i - 1][1] == cols[i + 1][1] == prev:
			tot -= 1
		else:
			prev = cols[i][1]
	print(tot)