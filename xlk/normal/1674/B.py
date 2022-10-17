for t in range(int(input())):
	s = input()
	z = (ord(s[0]) - 97) * 25 + (ord(s[1]) - 97)
	if s[0] > s[1]:
		z += 1
	print(z)