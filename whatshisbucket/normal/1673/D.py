# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

import math
M = 10 ** 9 + 7

t, = I()
for _ in range(t):
	b, q, y = I()
	c, r, z = I()
	prevc = c - r
	nextc = c + r * z
	lastb = b + q * (y - 1)
	if c < b or nextc - r > lastb or c % q != b % q or r % q != 0:
		print(0)
	elif prevc < b or nextc > lastb:
		print(-1)
	else:
		factors = []
		for i in range(1, int(r ** 0.5) + 3):
			if r % i == 0:
				factors.append(i)
				factors.append(r // i)
		factors = list(set(factors))
		tot = 0
		for factor in factors:
			if factor * q // math.gcd(factor, q) == r:
				tot = (tot + (r // factor) ** 2) % M
		print(tot)