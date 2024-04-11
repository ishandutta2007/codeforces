s = ''
for i in range(8):
	s += raw_input()

W = 9 * s.count('Q') + 5 * s.count('R') + 3 * s.count('B') + 3 * s.count('N') + s.count('P')
B = 9 * s.count('q') + 5 * s.count('r') + 3 * s.count('b') + 3 * s.count('n') + s.count('p')
if W == B:
	print 'Draw'
elif W > B:
	print 'White'
else:
	print 'Black'