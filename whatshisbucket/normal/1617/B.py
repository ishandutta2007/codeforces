import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,inpu().split())]

t = I()[0]
for _ in range(t):
	n = I()[0]
	if n % 2 == 0:
		print(n // 2, n // 2 - 1, 1)
	else:
		if (n // 2) % 2 == 0:
			print(n // 2 + 1, n // 2 - 1, 1)
		else:
			print(n // 2 + 2, n // 2 - 2, 1)