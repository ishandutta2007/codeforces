# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

I=lambda: int(input())

t = I()
for _ in range(t):
	a = 1
	b = 3
	modulus = 1
	val = 0
	for i in range(30):
		print('?', a, b)
		x = I()
		if x == 2 * modulus:
			val += modulus
			modulus *= 2
		else:
			modulus *= 2
		a = modulus - val
		b = a + 2 * modulus
	print('!', val)