import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	if k == 1:
		print('YES')
		for i in range(n):
			print(i + 1)
	elif n % 2 == 1:
		print('NO')
	else:
		nn = n // 2
		print('YES')
		for j in range(nn):
			a = [i + j * 2 * k for i in range(1, 2 * k) if i % 2 == 1]
			b = [i + j * 2 * k for i in range(1, 2 * k + 1) if i % 2 == 0]
			print(*a)
			print(*b)