n, m = map(int, raw_input().split())
def F(n, x):
	if n == 1:
		return [1][x]
	elif n == 2:
		return [3, 4][x]
	elif n % 2 == 0:
		return ([1] * (n - 1) + [n / 2 - 1])[x]
	elif n % 2 == 1:
		return ([2] + [1] * (n - 2) + [(n + 1) / 2])[x]
for i in range(n):
	for j in range(m):
		print F(n, i) * F(m, j),
	print