for t in range(int(input())):
	s = input()
	a = [int(i) for i in s]
	if sum(a[:3]) == sum(a[3:]):
		print('YES')
	else:
		print('NO')