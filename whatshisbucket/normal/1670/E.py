import io,os
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda: [*map(int, read.readline().split())]

#import sys
#I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	p, = I()
	n = 1 << p
	graph = [[] for i in range(n)]
	edges = []
	for i in range(n - 1):
		u, v = I()
		u -= 1
		v -= 1
		edges.append((u, v))
		graph[u].append(v)
		graph[v].append(u)
	parents = [None] * n
	children = [[] for i in range(n)]
	layer = [0]
	nodevals = {}
	nodevals[0] = n
	edgevals = {}
	curr = 1
	i = 1
	while layer:
		newlayer = []
		for guy in layer:
			for child in graph[guy]:
				if child != parents[guy]:
					if i % 2 == 1:
						edgevals[(guy, child)] = curr ^ n
						nodevals[child] = curr
					else:
						edgevals[(guy, child)] = curr
						nodevals[child] = curr ^ n
					curr += 1
					parents[child] = guy
					newlayer.append(child)
					children[guy].append(child)
		layer = newlayer
		i += 1
	print(1)
	print(*[nodevals[i] for i in range(n)])
	out = []
	for u, v in edges:
		if (u, v) in edgevals:
			out.append(edgevals[(u, v)])
		else:
			out.append(edgevals[(v, u)])
	print(*out)