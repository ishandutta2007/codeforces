for t in range(int(input())):
	n, k = map(int, input().split())
	print((k - 1) // (n - 1) * n + (k - 1) % (n - 1) + 1)