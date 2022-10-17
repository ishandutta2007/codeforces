for t in range(int(input())):
	s = input()
	t = input()
	if t == 'a':
		print(1)
	elif 'a' in t:
		print(-1)
	else:
		print(2 ** s.count('a'))