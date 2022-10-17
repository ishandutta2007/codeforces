t = int(input())
for tt in range(t):
	n = int(input())
	if n == 1:
		print('a')
	elif n % 2 == 0:
		print('a' * (n // 2) + 'b' + 'a' * (n // 2 - 1))
	else:
		print('a' * (n // 2) + 'b' + 'a' * (n // 2 - 1) + 'c')