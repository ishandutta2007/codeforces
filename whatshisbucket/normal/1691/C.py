# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	s = input()
	curr = 11 * s.count('1')
	if curr == 0:
		print(0)
		continue
	start = s.index('1')
	end = s[::-1].index('1')
	if end <= k:
		k -= end
		curr -= 10
	if start <= k and curr > 1:
		k -= start
		curr -= 1
	print(curr)