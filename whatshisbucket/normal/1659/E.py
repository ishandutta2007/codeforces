import io,os
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda: [*map(int, read.readline().split())]

# import sys
# I=lambda:[*map(int,sys.stdin.readline().split())]

n, m = I()
edges = [[] for i in range(n)]
for i in range(m):
	u, v, w = I()
	u -= 1
	v -= 1
	edges[u].append((v, w))
	edges[v].append((u, w))

comps = [[-1] * n for i in range(30)]
speccomps = [[-1] * n for i in range(30)]
even = [0] * n
for i in range(n):
	for v, w in edges[i]:
		if w % 2 == 0:
			even[i] = 1
for i in range(30):
	check = comps[i]
	count = 0
	for j in range(n):
		if check[j] == -1:
			check[j] = count
			layer = [j]
			while layer:
				newlayer = []
				for guy in layer:
					for v, w in edges[guy]:
						if check[v] == -1 and w >> i & 1:
							check[v] = count
							newlayer.append(v)
				layer = newlayer
			count += 1
for i in range(1, 30):
	check = speccomps[i]
	count = 0
	for j in range(n):
		if check[j] == -1:
			check[j] = count
			layer = [j]
			while layer:
				newlayer = []
				for guy in layer:
					for v, w in edges[guy]:
						if check[v] == -1 and w % 2 == 1 and w >> i & 1:
							check[v] = count
							newlayer.append(v)
				layer = newlayer
			count += 1

escape = [[]]
for i in range(1, 30):
	check = speccomps[i]
	leave = [0] * n
	for i in range(n):
		if even[i]:
			leave[check[i]] = 1
	escape.append(leave)

q, = I()
for _ in range(q):
	u, v = I()
	u -= 1
	v -= 1
	good = False
	for i in range(30):
		if comps[i][u] == comps[i][v]:
			good = True
	if good:
		print(0)
	else:
		good = False
		for i in range(1, 30):
			if escape[i][speccomps[i][u]]:
				good = True
		if good:
			print(1)
		else:
			print(2)