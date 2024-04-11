# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	graph = [[] for i in range(n)]
	parents = [None] * n
	children = [[] for i in range(n)]
	for i in range(n - 1):
		u, v = I()
		u -= 1
		v -= 1
		graph[u].append(v)
		graph[v].append(u)

	layer = [0]
	i = 0
	vals = [None] * n
	while layer != []:
		i += 1
		newlayer = []
		for guy in layer:
			if i % 2 == 0:
				vals[guy] = -len(graph[guy])
			else:
				vals[guy] = len(graph[guy])
			for boi in graph[guy]:
				if parents[boi] is None and boi != 0:
					parents[boi] = guy
					children[guy].append(boi)
					newlayer.append(boi)
		layer = newlayer
	#print(children)
	# vals = [None] * n
	# above = [None] * n
	# above[0] = -1
	# vals[0] = len(children[0])
	# q = children[0]
	# qind = 0
	# big = len(q)
	# while qind < len(q):
	# 	v = q[qind]
	# 	aa = above[parents[v]]
	# 	above[v] = aa * len(children[parents[v]]) + vals[parents[v]]
	# 	if qind < big:
	# 		above[v] -= aa
	# 	l = len(children[v])
	# 	vals[v] = aa - l * above[v]
	# 	q.extend(children[v])
	# 	qind += 1
	# print(*above)
	print(*vals)