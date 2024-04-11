# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]


t, = I()
for _ in range(t):
	n, = I()
	parents = [None] + [guy - 1 for guy in I()]
	colors = input()
	children = [[] for i in range(n)]
	for i in range(1, n):
		children[parents[i]].append(i)
	black = [0] * n
	white = [0] * n
	degs = [len(children[i]) for i in range(n)]
	order = [i for i in range(n) if degs[i] == 0]
	oind = 0
	while oind < len(order):
		v = order[oind]
		if v != 0:
			degs[parents[v]] -= 1
			if degs[parents[v]] == 0:
				order.append(parents[v])
		oind += 1
	balanced = 0
	for v in order:
		tblack = 0
		twhite = 0
		for w in children[v]:
			tblack += black[w]
			twhite += white[w]
		if colors[v] == 'W':
			twhite += 1
		else:
			tblack += 1
		black[v] = tblack
		white[v] = twhite
		if tblack == twhite:
			balanced += 1
	print(balanced)