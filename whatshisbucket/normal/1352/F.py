# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n0, n1, n2 = I()
	if n1 == 0 and n0 == 0:
		print('1' * (n2 + 1))
	elif n1 == 0 and n2 == 0:
		print('0' * (n0 + 1))
	else:
		out = '0' * (n0 + 1) + '1' * (n2 + 1)
		n1 -= 1
		out += '01' * (n1 // 2)
		if n1 % 2 == 1:
			out += '0'
		print(out)