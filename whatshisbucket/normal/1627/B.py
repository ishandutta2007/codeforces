import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

odd = [2 * x ** 2 - 2 * x + 1 for x in range(1, 1000)]

t, = I()
for _ in range(t):
	n, m = I()
	dist = [0] * (n + m)
	for i in range(n):
		for j in range(m):
			if n % 2 == 1:
				diffn = abs(n // 2 - i)
			else:
				diffn = min(abs(n // 2 - i), abs(n // 2 - 1 - i))
			if m % 2 == 1:
				diffm = abs(m // 2 - j)
			else:
				diffm = min(abs(m // 2 - j), abs(m // 2 - 1 - j))
			dist[diffn + diffm] += 1
	sml = n // 2 + m // 2
	out = []
	for i in range(len(dist)):
		for j in range(dist[i]):
			out.append(i + sml)
	print(*out)