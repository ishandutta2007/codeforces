import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	a, b, c = I()
	if (2 * b - a) % c == 0 and 2 * b - a > 0:
		print('YES')
	elif (a - c) % 2 == 0 and ((a + c) // 2) % b == 0:
		print('YES')
	elif (2 * b - c) % a == 0 and 2 * b - c > 0:
		print('YES')
	else:
		print('NO')