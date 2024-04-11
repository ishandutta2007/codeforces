import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	I()
	n, m = I()
	s, t = I()
	M = 10 ** 9 + 7
	s -= 1
	t -= 1
	g = [[] for i in range(n)]
	for i in range(m):
		u, v = I()
		g[u - 1].append(v - 1)
		g[v - 1].append(u - 1)

	distances = [M] * n
	distances[s] = 0
	i = 0
	paths = {s: 1}
	tot = 0
	while i <= distances[t]:
		i += 1
		newpaths = {}
		for v in paths:
			for w in g[v]:
				if distances[w] >= i - 1:
					distances[w] = min(distances[w], i)
					if w in newpaths:
						newpaths[w] = (newpaths[w] + paths[v]) % M
					else:
						newpaths[w] = paths[v]
		paths = newpaths
		if t in paths:
			tot += paths[t]
	print(tot % M)