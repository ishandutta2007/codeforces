import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	mat = []
	for i in range(n):
		mat.append(I())

	tot = 0
	i = 1
	while i < n:
		j = 0
		k = i
		while k < n:
			tot ^= mat[j][k]
			tot ^= mat[j][n - 1 - k]
			k += 2
			j += 2
		i += 4

	i = 3
	while i < n:
		j = 0
		k = i
		while k < n:
			tot ^= mat[k][j]
			tot ^= mat[k][n - 1 - j]
			k += 2
			j += 2
		i += 4

	print(tot)