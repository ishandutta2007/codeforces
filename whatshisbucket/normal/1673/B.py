# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input()
	x = len(set(s))
	for i in range(len(s) + 1 - x):
		y = len(set(s[i:i + x]))
		if y < x:
			print('NO')
			break
	else:
		print('YES')