for t in range(int(input())):
	x, y = map(int, input().split())
	if y % x:
		print(0, 0)
	else:
		print(1, y // x)