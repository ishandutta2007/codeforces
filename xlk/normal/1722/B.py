t = int(input())
for tt in range(t):
	n = int(input())
	s = input()
	t = input()
	if s.replace('B', 'G') == t.replace('B', 'G'):
		print('YES')
	else:
		print('NO')