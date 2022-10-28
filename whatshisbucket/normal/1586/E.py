import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

n, m = map(int, inpu().split())
neigh = {i:[] for i in range(1, n+1)}
for i in range(m):
	x, y = map(int, inpu().split())
	neigh[x].append(y)
	neigh[y].append(x)

q = int(inpu())
queries = []
appearances = [0]*n
for i in range(q):
	x, y = map(int, inpu().split())
	appearances[x-1] += 1
	appearances[y-1] += 1
	queries.append((x,y))

odds = 0
for guy in appearances:
	if guy%2 == 1:
		odds += 1
if odds > 0:
	prin("NO\n")
	prin(str(odds//2))
else:
	prin('YES\n')
	ancestors = {1:None}
	layer = [1]
	while layer != []:
		newlayer = []
		for v in layer:
			for n in neigh[v]:
				if n not in ancestors:
					ancestors[n] = v
					newlayer.append(n)
		layer = newlayer

	for a, b in queries:
		to = [a]
		curr = a
		while ancestors[curr] is not None:
			curr = ancestors[curr]
			to.append(curr)
		fro = [b]
		curr = b
		while ancestors[curr] is not None:
			curr = ancestors[curr]
			fro.append(curr)
		i = -1
		while i+len(to) >= 0 and i+len(fro) >= 0 and to[i] == fro[i]:
			i -= 1
		useto = to[:i+1]
		usefro = fro[:i+1]
		path = useto + [to[i+1]] + usefro[::-1]
		prin(str(len(path)))
		prin('\n')
		prin(' '.join([str(v) for v in path]))
		prin('\n')