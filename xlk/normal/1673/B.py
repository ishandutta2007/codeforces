for t in range(int(input())):
	s = input()
	l = len(set(s))
	for i in range(l, len(s)):
		if s[i] != s[i - l]:
			print('NO')
			break
	else:
		print('YES')