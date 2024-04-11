# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	x, = I()
	ones = bin(x).count('1')
	if ones == 1:
		if x == 1:
			print(3)
		else:
			print(x + 1)
	else:
		for i in range(30):
			if x >> i & 1:
				print(1 << i)
				break