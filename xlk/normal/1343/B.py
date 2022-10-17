t = int(input())
for tt in range(t):
	n = int(input())
	if n % 4 == 0:
		print('YES')
		a = list(range(2, n + 1, 2)) + list(range(1, n - 1, 2)) + [sum(range(2, n + 1, 2)) - sum(range(1, n - 1, 2))]
		print(' '.join(map(str, a)))
	else:
		print('NO')