import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
prin = sys.stdout.write

t, = I()
for _ in range(t):
	I()
	n, m = I()
	points = []
	for i in range(m):
		x, w = I()
		points.append((x, w, i))
	points.sort(key = lambda x: x[1])
	use = points[:2 * n]
	print(sum(guy[1] for guy in use))
	use.sort()
	for i in range(n):
		prin(str(use[i][2] + 1) + ' ' + str(use[-i - 1][2] + 1) + '\n')