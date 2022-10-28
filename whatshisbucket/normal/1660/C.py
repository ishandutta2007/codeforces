# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input()
	pairs = 0
	n = len(s)
	seen = set()
	for i in range(n):
		if s[i] not in seen:
			seen.add(s[i])
		else:
			pairs += 1
			seen = set()
	print(n - 2 * pairs)