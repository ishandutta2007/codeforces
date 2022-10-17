t = int(input())
for tt in range(t):
	n = input()
	s = input()
	if s.count('1') < 2 and s.count('0') < 2:
		print('YES')
	else:
		print('NO')