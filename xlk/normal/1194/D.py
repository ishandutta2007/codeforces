for t in range(int(input())):
	n, k = map(int, input().split())
	if k % 3 == 0:
		n %= k + 1
	if n == k or n % 3 != 0:
		print('Alice')
	else:
		print('Bob')