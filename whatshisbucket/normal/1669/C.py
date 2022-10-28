# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	x = a[0::2]
	y = a[1::2]
	x = [fuy % 2 for fuy in x]
	y = [guy % 2 for guy in y]
	if len(set(x)) == 1 and len(set(y)) == 1:
		print('YES')
	else:
		print('NO')