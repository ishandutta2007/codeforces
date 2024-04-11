# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input()
	n = len(s)
	net = 0
	for i in range(n):
		if s[i] == 'A':
			net += 1
		else:
			net -= 1
			if net < 0:
				print('NO')
				break
	else:
		if s[-1] == "B":
			print('YES')
		else:
			print('NO')