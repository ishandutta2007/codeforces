import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
prin = sys.stdout.write

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	if sum(a) % n == 0:
		print(0)
	else:
		print(1)