t = int(input())
for tt in range(t):
	a, b, c = map(int, input().split())
	s = a + b + c
	if s % 9 == 0 and min(a, b, c) >= s / 9:
		print('YES')
	else:
		print('NO')