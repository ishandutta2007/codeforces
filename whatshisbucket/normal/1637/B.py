import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	tot = 0
	for i in range(n + 1):
		tot += i * (n + 1 - i)
	for i in range(n):
		if a[i] == 0:
			tot += (i + 1) * (n - i)
	print(tot)