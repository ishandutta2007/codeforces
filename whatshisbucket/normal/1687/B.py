# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

I=lambda:[*map(int, input().split())]
n, m = I()
weights = [0] * m
curr = ['0'] * m
for i in range(m):
	curr[i] = '1'
	print('?', ''.join(curr))
	weights[i] = int(input())
	curr[i] = '0'

x = [(i, weights[i]) for i in range(m)]
x.sort(key = lambda x: x[1])
currsum = 0
curr[x[0][0]] = '1'
currsum = x[0][1]
for i in range(1, m):
	ind, val = x[i]
	curr[ind] = '1'
	print('?', ''.join(curr))
	tree = int(input())
	if tree != currsum + val:
		curr[ind] = '0'
	else:
		currsum += val
print('!', currsum)