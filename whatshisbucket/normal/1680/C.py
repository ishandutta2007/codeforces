# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input()
	if '0' not in s or '1' not in s:
		print(0)
		continue
	ones = []
	n = len(s)
	for i in range(n):
		if s[i] == '1':
			ones.append(i)
	o = len(ones)
	aind = 0
	bind = 0
	best = float('inf')
	while bind < o:
		x = aind + o - bind - 1
		y = ones[bind] - ones[aind] - (bind - aind)
		if max(x, y) < best:
			best = max(x, y)
		if x >= y:
			bind += 1
		else:
			aind += 1
	print(best)