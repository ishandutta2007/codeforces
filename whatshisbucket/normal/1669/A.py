# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	if n < 1400:
		print('Division 4')
	elif n < 1600:
		print('Division 3')
	elif n < 1900:
		print('Division 2')
	else:
		print('Division 1')