import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	seen = [0] * (n + 1)
	for i in range(n):
		while a[i] > n:
			a[i] //= 2
		while seen[a[i]] == 1 and a[i] > 0:
			a[i] //= 2
		seen[a[i]] = 1
	if 0 in a:
		print('NO')
	else:
		print('YES')