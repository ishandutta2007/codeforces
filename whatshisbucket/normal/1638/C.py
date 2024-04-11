import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	p = I()
	big = 0
	comp = 0
	for i in range(n):
		big = max(big, p[i])
		if big == i + 1:
			comp += 1
	print(comp)