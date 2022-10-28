import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	if k == n - 1:
		if n == 4:
			print(-1)
		else:
			print(n - 1, n - 2)
			print(1, n // 2 + 1)
			print(0, n // 2 - 2)
			for i in range(2, n // 2):
				if i != n // 2 - 2:
					print(i, n - 1 - i)
	elif k == 0:
		for i in range(n // 2):
			print(i, n - 1 - i)
	else:
		print(k, n - 1)
		print(0, n - 1 - k)
		for i in range(1, n // 2):
			if i != k and i != n - 1 - k:
				print(i, n - 1 - i)