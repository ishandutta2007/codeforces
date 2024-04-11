# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	counts = {}
	for i in range(n):
		x = sys.stdin.readline().strip()
		if x in counts:
			counts[x] += 1
		else:
			counts[x] = 1
	pairs = 0
	for guy in counts:
		for guy1 in counts:
			if (guy[0] == guy1[0] or guy[1] == guy1[1]) and guy != guy1:
				pairs += counts[guy] * counts[guy1]
	print(pairs // 2)