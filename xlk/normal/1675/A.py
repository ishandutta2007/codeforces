for t in range(int(input())):
	a, b, c, x, y = map(int, input().split())
	if x <= a + c and y <= b + c and x + y <= a + b + c:
		print('YES')
	else:
		print('NO')