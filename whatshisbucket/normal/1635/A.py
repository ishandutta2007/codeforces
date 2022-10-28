import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	x = a[0]
	for i in range(n):
		x |= a[i]
	print(x)