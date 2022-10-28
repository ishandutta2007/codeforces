# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	a = I()
	bad = [0] * 31
	for guy in a:
		curr = guy
		for i in range(31):
			if not curr & 1:
				bad[i] += 1
			curr = curr >> 1
	#print(bad)
	curr = 0
	for i in range(31):
		if bad[i] == 0:
			curr += 1 << i
	left = k
	for j in range(30, -1, -1):
		if bad[j] <= left:
			if bad[j] > 0:
				curr += 1 << j
				left -= bad[j]
	print(curr)