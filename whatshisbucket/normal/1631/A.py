import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	b = I()
	big = 0
	big2 = 0
	for i in range(n):
		x = max(a[i], b[i])
		y = min(a[i], b[i])
		if x > big:
			big = x
		if y > big2:
			big2 = y

	print(big * big2)