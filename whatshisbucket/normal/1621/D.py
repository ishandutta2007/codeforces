import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	cost = []
	for i in range(2 * n):
		cost.append(I())

	cos = 0
	for i in range(n, 2 * n):
		for j in range(n, 2 * n):
			cos += cost[i][j]

	best = min([cost[0][n],cost[0][-1],cost[n - 1][n],cost[n - 1][-1], cost[n][0], cost[n][n - 1], cost[-1][0], cost[-1][n - 1]])
	print(cos + best)