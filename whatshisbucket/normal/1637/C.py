import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	middle = a[1:-1]
	if middle.count(1) == len(middle) or len(middle) == 1 and middle[0] % 2 == 1:
		print('-1')
		continue
	tot = 0
	for guy in middle:
		tot += (guy + 1) // 2
	print(tot)