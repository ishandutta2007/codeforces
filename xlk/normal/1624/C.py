for t in range(int(input())):
	n = int(input())
	s = set()
	for i in map(int, input().split()):
		while i > n or i in s:
			i //= 2
		if i == 0:
			print('NO')
			break
		s.add(i)
	else:
		print('YES')