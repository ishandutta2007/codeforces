import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	if n % 7 == 0:
		print(n)
	else:
		x = 10 * (n // 10)
		while x % 7 != 0:
			x += 1
		print(x)