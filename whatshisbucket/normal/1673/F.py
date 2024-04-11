# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

import math

n, k = [*map(int, input().split())]
row = [1]
while len(row) < 31:
	row = row + [4 * max(row)] + row

column = [guy * 2 for guy in row]

for i in range(n):
	print(*row[:n - 1])
for i in range(n - 1):
	print(*([column[i]] * n))
vals = [[0] * 32 for i in range(32)]
for j in range(32):
	for i in range(32):
		if i == 0 and j > 0:
			vals[j][i] = vals[j - 1][i] ^ column[j - 1]
		elif i != 0:
			vals[j][i] = vals[j][i - 1] ^ row[i - 1]
#print(vals)

locs = {}
for i in range(32):
	for j in range(32):
		locs[vals[i][j]] = (i, j)

curr = 0
for i in range(k):
	x = int(input())
	a, b = locs[x ^ curr]
	print(a + 1, b + 1)
	curr ^= x