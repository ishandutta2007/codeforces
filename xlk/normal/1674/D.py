for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(n % 2, n, 2):
		if a[i] > a[i + 1]:
			a[i], a[i + 1] = a[i + 1], a[i]
	if sorted(a) == a:
		print('YES')
	else:
		print('NO')