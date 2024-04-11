import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	print(a.index(max(a)) + 1, a.index(min(a)) + 1)