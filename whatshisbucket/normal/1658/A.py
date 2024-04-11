# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	s = input()
	inds = []
	for i in range(n):
		if s[i] == '0':
			inds.append(i)
	needed = 0
	for i in range(len(inds) - 1):
		needed += max(0, 3 - (inds[i + 1] - inds[i]))
	print(needed)