# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	s = [*map(int, [*input()])]
	if k % 2:
		for i in range(n):
			s[i] = 1 - s[i]
	flips = [0] * n
	left = k
	for i in range(n):
		if left == 0:
			break
		if s[i] == 0:
			s[i] = 1
			left -= 1
			flips[i] += 1
	if left > 0:
		flips[-1] += left
		if left % 2 == 1:
			s[-1] = 1 - s[-1]
	print(''.join(str(guy) for guy in s))
	print(*flips)