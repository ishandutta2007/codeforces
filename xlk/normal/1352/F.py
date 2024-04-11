for t in range(int(input())):
	a, b, c = map(int, input().split())
	if b == 0 and c == 0:
		s = ('0' * (a + 1))
	elif b == 0 and a == 0:
		s = ('1' * (c + 1))
	else:
		s = '1'
		for i in range(b):
			s += str(i % 2)
		s = s.replace('0', '0' * (a + 1), 1)
		s = s.replace('1', '1' * (c + 1), 1)
	print(s)