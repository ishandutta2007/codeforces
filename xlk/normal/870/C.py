for _ in range(input()):
	n = input()
	print [n / 4 - n % 2, -1][n in [1, 2, 3, 5, 7, 11]]