import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	even = 1
	while n % 2 == 0:
		even *= 2
		n //= 2
	if n > 2 * even:
		print(2 * even)
	elif n > 1:
		print(n)
	else:
		print(-1)