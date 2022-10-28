# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]


t, = I()
for _ in range(t):
	n, = I()
	s = input()
	bad = 0
	segments = 0
	curr = -1
	for i in range(n // 2):
		if s[2 * i] != s[2 * i + 1]:
			bad += 1
		else:
			x = int(s[2 * i])
			if x != curr:
				segments += 1
				curr = x
	if segments == 0:
		segments = 1
	print(bad, segments)