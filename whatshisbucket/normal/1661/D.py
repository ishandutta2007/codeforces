# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, k = I()
b = I()
currsum = 0
start = [0] * n
currcnt = 0
i = n - 1
while i >= k:
	b[i] -= currsum
	needed = (b[i] - 1) // k + 1
	if needed < 0:
		needed = 0
	b[i] -= needed * k
	start[i - k + 1] += needed
	currcnt += needed
	currsum += k * needed
	currsum -= currcnt
	currcnt -= start[i]
	i -= 1
#print(start, b)
for i in range(k - 1, -1, -1):
	b[i] -= currsum
	currsum -= currcnt
	currcnt -= start[i]
big = 0
for i in range(k):
	big = max(big, (b[i] - 1) // (i + 1) + 1)
print(sum(start) + big)