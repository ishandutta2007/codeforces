# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	odd = False
	evens = 0
	sml = 50
	for guy in a:
		if guy % 2:
			odd = True
		else:
			evens += 1
		if not odd:
			curr = 0
			while guy % 2 == 0:
				curr += 1
				guy >>= 1
			sml = min(sml, curr)
	if odd:
		print(evens)
	else:
		print(sml + n - 1)