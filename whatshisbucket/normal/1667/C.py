# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, = I()
if n == 1:
	print(1)
	print(1, 1)
	exit()
extra = (n + 1) // 3
use = n - extra
if n % 3 == 0:
	spec = 1
elif n % 3 == 1:
	spec = 2
else:
	spec = 0
use = use - spec
currx = 0
curry = 0
print(use + spec)
while currx < use:
	print(currx + 1, curry + 1)
	currx += 1
	curry += 2
	if curry >= use:
		curry = 1
for i in range(spec):
	print(use + i + 1, use + i + 1)