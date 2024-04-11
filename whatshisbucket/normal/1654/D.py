# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

era = [0] * 200001
for i in range(2, 200001):
	if era[i] == 0:
		k = i
		while k < 200001:
			if era[k] == 0:
				era[k] = i
			k += i

M = 998244353
invs = [0] * 200001
for i in range(2, 200001):
	invs[i] = pow(i, M - 2, M)

import math
t, = I()
for _ in range(t):
	n, = I()
	invs = [0] * (n + 1)
	for i in range(1, n + 1):
		invs[i] = pow(i, M - 2, M)
	graph = [[] for i in range(n)]
	for i in range(n - 1):
		u, v, x, y = I()
		u -= 1
		v -= 1
		g = math.gcd(x, y)
		x //= g
		y //= g
		graph[u].append((v, y, x))
		graph[v].append((u, x, y))

	parents = [None] * n
	inds = [0] * n
	curr = 0
	exps = {}
	minexps = {}
	ratio = 1
	ratios = [0] * n
	while curr != None:
		if inds[curr] > 0:
			u, x, y = graph[curr][inds[curr] - 1]
			if u != parents[curr]:
				ratio = ratio * y * invs[x] % M
				while x > 1:
					p = era[x]
					exps[p] -= 1
					x //= p
				while y > 1:
					p = era[y]
					exps[p] += 1
					y //= p
		ratios[curr] = ratio
		if inds[curr] >= len(graph[curr]):
			curr = parents[curr]
		elif graph[curr][inds[curr]][0] == parents[curr]:
			inds[curr] += 1
		else:
			u, x, y = graph[curr][inds[curr]]
			parents[u] = curr
			ratio = ratio * x * invs[y] % M
			while x > 1:
				p = era[x]
				if p in exps:
					exps[p] += 1
				else:
					exps[p] = 1
					minexps[p] = 0
				x //= p
			while y > 1:
				p = era[y]
				if p in exps:
					exps[p] -= 1
				else:
					exps[p] = -1
					minexps[p] = -1
				y //= p
				minexps[p] = min(minexps[p], exps[p])
			inds[curr] += 1
			curr = u

	# print(ratio)
	# print(ratios)
	# print(minexps)
	tot = sum(ratios) % M
	for guy in minexps:
		for i in range(-minexps[guy]):
			tot = tot * guy % M
	print(tot)