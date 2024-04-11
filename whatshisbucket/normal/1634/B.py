import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, x, y = I()
	a = I()
	odd = sum(1 for i in range(n) if a[i] % 2)
	if odd % 2 == 0:
		if x % 2 == y % 2:
			print('Alice')
		else:
			print('Bob')
	else:
		if x % 2 == y % 2:
			print('Bob')
		else:
			print('Alice')