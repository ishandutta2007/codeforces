# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	l, r = I()
	a = set(I())

	x = [i for i in range(l, r + 1)]
	ones = [0] * 17
	for guy in x:
		curr = guy
		for i in range(17):
			ones[i] += curr & 1
			curr >>= 1
	aones = [0] * 17
	for guy in a:
		curr = guy
		for i in range(17):
			aones[i] += curr & 1
			curr >>= 1
	out = 0
	for i in range(17):
		if ones[i] != aones[i]:
			out += 1 << i
	print(out)