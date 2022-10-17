def S():
	s = raw_input()
	while True:
		if s.find('u') != -1 or s.find('kh') != -1:
			s = s.replace('u', 'oo').replace('kh', 'h')
		else:
			return s
print len(set(S() for i in range(input())))