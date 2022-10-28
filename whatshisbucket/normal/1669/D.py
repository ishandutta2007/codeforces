# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	s = input().split('W')
	for guy in s:
		if len(set(guy)) == 1:
			print('NO')
			break
	else:
		print('YES')