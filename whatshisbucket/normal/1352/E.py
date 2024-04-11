# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	isspecial = [0] * (n + 1)
	for i in range(n - 1):
		curr = a[i] + a[i + 1]
		j = i + 1
		while j < n and curr <= n:
			isspecial[curr] = 1
			if j < n - 1:
				curr += a[j + 1]
			j += 1
	tot = 0
	for guy in a:
		if isspecial[guy]:
			tot += 1
	print(tot)