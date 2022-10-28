import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, = I()
botneigh = [[] for i in range(n)]
topneigh = [[] for i in range(n)]
edges = []
for i in range(2 * n):
	x, y = I()
	x = x - 1
	y = y - n - 1
	edges.append((x, y))
	botneigh[x].append(y)
	topneigh[y].append(x)

toplen = [0] * n
botlen = [0] * n
for i in range(n):
	if toplen[i] == 0:
		prev = i
		curr = topneigh[i][0]
		cycle = [prev]
		while curr != cycle[0] or len(cycle) % 2 == 1:
			cycle.append(curr)
			ccurr = curr
			if len(cycle) % 2 == 0:
				for j in range(2):
					if botneigh[curr][j] != prev:
						curr = botneigh[curr][j]
						break
			else:
				for j in range(2):
					if topneigh[curr][j] != prev:
						curr = topneigh[curr][j]
						break
			prev = ccurr
		for i in range(len(cycle)):
			if i % 2 == 0:
				toplen[cycle[i]] = len(cycle)
			else:
				botlen[cycle[i]] = len(cycle)

# print(topneigh)
# print(botneigh)
# print(toplen)
# print(botlen)
tot = 0
xtot = 0
for x, y in edges:
	old = tot
	smlbot = x
	bigbot = x
	smltop = y
	bigtop = y
	curr = x
	prev = y
	for i in range(toplen[y] // 2):
		for j in range(2):
			if botneigh[curr][j] != prev:
				nex = botneigh[curr][j]
		# print(x, y, prev, curr, nex)
		if nex < smltop:
			tot += (smltop - nex) * (n - bigtop) * (smlbot + 1) * (n - bigbot)
			smltop = nex
		elif nex > bigtop:
			tot += (smltop + 1) * (nex - bigtop) * (smlbot + 1) * (n - bigbot)
			bigtop = nex
		prev = curr
		curr = nex
		for j in range(2):
			if topneigh[curr][j] != prev:
				nex = topneigh[curr][j]
		# print(x, y, prev, curr, nex)
		if nex < smlbot:
			smlbot = nex
		elif nex > bigbot:
			bigbot = nex
		prev = curr
		curr = nex
	#print(tot - old)
	# print(x, y, smlbot, bigbot, smltop, bigtop)
	# print(x, y, (smltop + 1) * (n - bigtop) * (smlbot + 1) * (n - bigbot))
	xtot += (smltop + 1) * (n - bigtop) * (smlbot + 1) * (n - bigbot)
for x, y in edges:
	smlbot = x
	bigbot = x
	smltop = y
	bigtop = y
	curr = y
	prev = x
	for i in range(toplen[y] // 2):
		for j in range(2):
			if topneigh[curr][j] != prev:
				nex = topneigh[curr][j]
		if nex < smlbot:
			tot += (smlbot - nex) * (n - bigbot) * (smltop + 1) * (n - bigtop)
			smlbot = nex
		elif nex > bigbot:
			tot += (nex - bigbot) * (smlbot + 1) * (smltop + 1) * (n - bigtop)
			bigbot = nex
		prev = curr
		curr = nex
		for j in range(2):
			if botneigh[curr][j] != prev:
				nex = botneigh[curr][j]
		if nex < smltop:
			smltop = nex
		elif nex > bigtop:
			bigtop = nex
		prev = curr
		curr = nex

# print(tot)
# print(xtot)
print(tot // 2 + xtot // 2)