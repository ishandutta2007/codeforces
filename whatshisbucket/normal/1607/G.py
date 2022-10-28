import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	inpu()
	n, m = map(int, inpu().split())
	pairs = []
	for i in range(n):
		x, y = map(int, inpu().split())
		pairs.append((x, y, i))

	pairs.sort(key = lambda x : x[0] + x[1])
	fish = sum(g[0] for g in pairs)
	meat = sum(g[1] for g in pairs)
	minf = 0
	maxf = 0
	for i in range(n):
		minf += max(0, m - pairs[i][1])
		maxf += min(m, pairs[i][0])
	ideal = (n * m + fish - meat) // 2
	needed = max(0, min(maxf, ideal) - minf)
	fish -= needed + minf
	meat -= m * n - needed - minf
	prin(str(abs(fish - meat)))
	prin('\n')
	take = [0] * n
	for i in range(n):
		sml = max(0, m - pairs[i][1])
		big = min(m, pairs[i][0])
		if big - sml > needed:
			take[pairs[i][2]] = needed + sml
			needed = 0
		else:
			take[pairs[i][2]] = big
			needed -= big - sml
	for i in range(n):
		prin(str(take[i]) + ' ' + str(m - take[i]) + '\n')