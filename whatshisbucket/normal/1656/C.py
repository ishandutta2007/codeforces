import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n = I()
	a = set(I())
	if 1 in a:
		for guy in a:
			if guy + 1 in a:
				print('NO')
				break
		else:
			print('YES')
	else:
		print('YES')