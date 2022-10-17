t = int(input())
for tt in range(t):
	n = int(input())
	if n < 6:
		print(15)
	else:
		print((n + 1) // 2 * 5)