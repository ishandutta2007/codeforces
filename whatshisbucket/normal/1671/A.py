# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input()
	for i in range(len(s) - 2):
		if s[i] == s[i + 2] and s[i] != s[i + 1]:
			print('NO')
			break
	else:
		if len(s) == 1 or s[0] != s[1] or s[-1] != s[-2]:
			print('NO')
		else:
			print('YES')