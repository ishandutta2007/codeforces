t = int(input())
for tt in range(t):
	n = int(input())
	a = [input() for i in range(n)]
	z = 0
	for i in range(n // 2):
		for j in range((n + 1) // 2):
			s = int(a[i][j]) + int(a[j][n - 1 - i]) + int(a[n - 1 - i][n - 1 - j]) + int(a[n - 1 - j][i])
			z += min(s, 4 - s)
	print(z)