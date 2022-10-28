import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	s = input()
	if len(s) <= 2 and s not in ['00', '11']:
		print('YES')
	else:
		print('NO')