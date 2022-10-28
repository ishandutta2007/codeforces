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
	counts[0] = 0
	for guy in a:
		if guy in counts:
			counts[guy] += 1
		else:
			counts[guy] = 1
	if counts[0] > 0:
		print(n - counts[0])
	else:
		good = False
		for guy in counts:
			if counts[guy] > 1:
				good = True
		if good:
			print(n)
		else:
			print(n + 1)