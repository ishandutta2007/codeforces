# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	I()
	n, = I()
	mat = []
	for i in range(n):
		mat.append(input())
	ones = [0] * n
	for i in range(n):
		for j in range(n):
			if mat[i][j] == '1':
				ones[i - j] += 1
	print(sum(ones) + n - 2 * max(ones))