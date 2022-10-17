for t in range(int(input())):
	n = int(input())
	if n < 4:
		print(-1)
	else:
		a = list(range(1, n + 1, 2))[::-1] + [4, 2] + list(range(6, n + 1, 2))
		print(*a)