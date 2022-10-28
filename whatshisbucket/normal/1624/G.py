import io,os
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda:map(int, read.readline().split())

# import sys
# I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
def do():
	I()
	n, m = I()
	graph = {i: set() for i in range(n)}
	for i in range(m):
		u, v, w = I()
		graph[u - 1].add((v - 1, w))
		graph[v - 1].add((u - 1, w))

	out = 0
	for i in range(n):
		for v, w in graph[i]:
			out |= w
	if m == n - 1:
		print(out)
		return

	tot = 0
	for i in range(29, -1, -1):
		if not (out >> i) & 1:
			continue
		visited = [0] * n
		visited[0] = 1
		layer = [0]
		while layer != []:
			newlayer = []
			for guy in layer:
				for v, w in graph[guy]:
					if not visited[v] and not (w >> i) & 1:
						newlayer.append(v)
						visited[v] = 1
			layer = newlayer
		if 0 not in visited:
			for j in range(n):
				new = []
				for guy in graph[j]:
					if (guy[1] >> i) & 1:
						new.append(guy)
				for guy in new:
					graph[j].remove(guy)
		else:
			tot += 1 << i
	print(tot)

for _ in range(t):
	do()