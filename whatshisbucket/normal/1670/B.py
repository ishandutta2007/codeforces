# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	s = sys.stdin.readline()
	t = sys.stdin.readline().split()
	k = int(t[0])
	c = set(t)
	longest = 0
	i = 0
	for char in s:
		if char not in c:
			i += 1
		else:
			longest = max(longest, i)
			i = 1
	print(longest)