for t in range(int(input())):
	n, m = map(int, input().split())
	f = [0 for i in range(n + m)]
	g = [0 for i in range(n + m)]
	a = []
	for i in range(n):
		a.append(list(map(int, input().split())))
		for j in range(m):
			f[i + j] += a[i][j]
			g[i - j + m] += a[i][j]
	z = 0
	for i in range(n):
		for j in range(m):
			z = max(z, f[i + j] + g[i - j + m] - a[i][j])
	print(z)