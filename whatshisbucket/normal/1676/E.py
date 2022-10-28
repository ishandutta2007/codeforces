# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]


t, = I()
for _ in range(t):
	n, q = I()
	a = I()
	a.sort(reverse = True)
	partial = [0]
	for i in range(n):
		partial.append(partial[-1] + a[i])
	for j in range(q):
		x, = I()
		if x > partial[-1]:
			print(-1)
		else:
			sml = 0
			big = n
			while big - sml > 1:
				mid = (big + sml) // 2
				if x > partial[mid]:
					sml = mid
				else:
					big = mid
			print(big)