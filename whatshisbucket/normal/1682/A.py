# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	s = input()
	mid = s[n // 2]
	tot = 0
	i = n // 2 - 1
	while i >= 0 and s[i] == mid:
		tot += 1
		i -= 1
	tot *= 2
	if n % 2 == 1:
		tot += 1
	print(tot)