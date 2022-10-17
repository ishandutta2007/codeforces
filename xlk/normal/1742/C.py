t = int(input())
for tt in range(t):
	input()
	r = 0
	for i in range(8):
		s = input()
		if s.count('R') == 8:
			r = 1
	print('BR'[r])