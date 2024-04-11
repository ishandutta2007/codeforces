t = int(input())
for tt in range(t):
	n = int(input())
	if n == 2:
		print(2, 1)
	elif n == 3:
		print(-1)
	else:
		a = list(range(3, n + 1)) + [1, 2]
		print(*a)