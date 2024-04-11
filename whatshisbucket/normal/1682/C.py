# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	a.sort()
	counts = {}
	for guy in a:
		if guy in counts:
			counts[guy] += 1
		else:
			counts[guy] = 1
	dupes = 0
	diff = len(counts)
	one = False
	for guy in counts:
		if counts[guy] > 1:
			dupes += 1
		one = True
	if not one:
		print((diff + dupes) // 2)
	else:
		print((diff + dupes + 1) // 2)