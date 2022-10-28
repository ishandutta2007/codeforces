import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	if a == sorted(a):
		print('NO')
	else:
		print('YES')