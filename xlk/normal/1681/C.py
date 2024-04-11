for tt in range(int(input())):
	n = int(input())
	a = list(zip(map(int, input().split()), map(int, input().split())))
	z = []
	for i in range(n):
		for j in range(1, n):
			if a[j - 1] > a[j]:
				z.append((j - 1, j))
				a[j - 1], a[j] = a[j], a[j - 1]
	for i in range(1, n):
		if a[i - 1][1] > a[i][1]:
			print(-1)
			break
	else:
		print(len(z))
		for x, y in z:
			print(x + 1, y + 1)