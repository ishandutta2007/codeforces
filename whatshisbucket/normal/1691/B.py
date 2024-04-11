# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	counts = {}
	for guy in a:
		if guy in counts:
			counts[guy] += 1
		else:
			counts[guy] = 1
	x = sorted([*counts.items()])
	out = []
	curr = 1
	bad = False
	for size, count in x:
		if count == 1:
			bad = True
		for i in range(curr + 1, curr + count):
			out.append(i)
		out.append(curr)
		curr += count
	if bad:
		print(-1)
		continue
	print(*out)