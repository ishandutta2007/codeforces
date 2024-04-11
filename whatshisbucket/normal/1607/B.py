t = int(input())
for _ in range(t):
	x, n = map(int, input().split())
	di = 1 if x % 2 == 1 else - 1
	if n % 4 == 0:
		print(x)
	elif n % 4 == 1:
		print(x + di * n)
	elif n % 4 == 2:
		print(x - di)
	else:
		print(x - di * (n + 1))