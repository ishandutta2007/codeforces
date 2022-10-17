for t in range(int(input())):
	n, k = map(int, input().split())
	a = []
	if n - 2 * k >= 0 and n % 2 == 0:
		a = [n - 2 * k + 2] + [2] * (k - 1)
	elif n - k >= 0 and (n - (k - 1)) % 2 == 1:
		a = [n - (k - 1)] + [1] * (k - 1)
	if a:
		print('YES')
		print(*a)
	else:
		print('NO')