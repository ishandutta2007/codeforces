import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	last = a[-1]
	ind = n - 1
	ops = 0
	while ind > 0:
		if a[ind - 1] == last:
			ind -= 1
		else:
			ops += 1
			ind = n - 2 * (n - ind)
	print(ops)