# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	a = I()
	if k >= n:
		print(0)
		continue
	a.sort()
	unique = 0
	prev = -1
	mex = k
	for guy in a:
		if guy != prev:
			prev = guy
			unique += 1
		if k + unique > guy:
			mex = k + unique
		else:
			break
	if mex >= n:
		print(0)
		continue
	counts = {}
	for guy in a:
		if guy in counts:
			counts[guy] += 1
		else:
			counts[guy] = 1
	things = []
	for guy in counts:
		if guy > mex:
			things.append(counts[guy])
	things.sort()
	#print(ones, mex)
	hurts = 0
	left = k
	for guy in things:
		if left == 0:
			break
		if left >= guy:
			left -= guy
			hurts += guy - 1
		else:
			hurts += left
			left = 0
	print(max(0, len(set(a)) + hurts - mex))