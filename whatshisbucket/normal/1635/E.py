import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

n, m = I()
orient = [0] * n

toward = [[] for i in range(n)]
away = [[] for i in range(n)]
for i in range(m):
	a, u, v = I()
	if a == 1:
		away[u - 1].append(v - 1)
		away[v - 1].append(u - 1)
	else:
		toward[u - 1].append(v - 1)
		toward[v - 1].append(u - 1)

comps = []
seen = [0] * n
for i in range(n):
	if not seen[i]:
		comp = [i]
		seen[i] = 1
		layer = [i]
		while layer:
			newlayer = []
			for guy in layer:
				for boi in toward[guy]:
					if not seen[boi]:
						seen[boi] = 1
						newlayer.append(boi)
				for boi in away[guy]:
					if not seen[boi]:
						seen[boi] = 1
						newlayer.append(boi)
			layer = newlayer
			comp.extend(newlayer)
		comps.append(comp)

dirs = [0] * n
locs = [0] * n
tot = 0

badbadbad = False
for comp in comps:
	dirs[comp[0]] = 1
	layer = [comp[0]]
	while layer:
		newlayer = []
		for guy in layer:
			for boi in toward[guy]:
				if dirs[boi] == dirs[guy]:
					badbadbad = True
				elif dirs[boi] == 0:
					dirs[boi] = -dirs[guy]
					newlayer.append(boi)
			for boi in away[guy]:
				if dirs[boi] == dirs[guy]:
					badbadbad = True
				elif dirs[boi] == 0:
					dirs[boi] = - dirs[guy]
					newlayer.append(boi)
		layer = newlayer

	x = {}
	for guy in comp:
		if dirs[guy] == -1:
			x[guy] = len(toward[guy])
		else:
			x[guy] = len(away[guy])
	ordering = []
	q = []
	qind = 0
	for guy in comp:
		if x[guy] == 0:
			q.append(guy)
	while qind < len(q):
		v = q[qind]
		ordering.append(v)
		if dirs[v] == -1:
			for guy in away[v]:
				x[guy] -= 1
				if x[guy] == 0:
					q.append(guy)
		else:
			for guy in toward[v]:
				x[guy] -= 1
				if x[guy] == 0:
					q.append(guy)
		qind += 1
	if len(ordering) < len(comp):
		badbadbad = True
	for i in range(len(ordering)):
		locs[ordering[i]] = tot + i
	tot += len(ordering)

if badbadbad:
	print('NO')
else:
	print('YES')
	out = []
	for i in range(n):
		dire = 'L' if dirs[i] == -1 else 'R'
		out.append(dire + ' ' + str(locs[i]))
	print('\n'.join(out))