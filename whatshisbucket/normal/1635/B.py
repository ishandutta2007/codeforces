import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	tot = 0
	for i in range(1, n - 1):
		if a[i] > a[i - 1] and a[i] > a[i + 1]:
			tot += 1
			a[i + 1] = a[i]
			if i + 2 < n:
				a[i + 1] = max(a[i + 1], a[i + 2])
	print(tot)
	print(*a)