import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	edges = []
	neigh = [[] for i in range(n)]
	for i in range(n - 1):
		a, b = I()
		edges.append((a - 1, b - 1))
		neigh[a - 1].append(b - 1)
		neigh[b - 1].append(a - 1)
	#print(neigh)
	for i in range(n):
		if len(neigh[i]) > 2:
			print(-1)
			break
		elif len(neigh[i]) == 1:
			start = i
	else:
		val = 1
		nums = [0] * n
		nex = neigh[start][0]
		old = start
		while len(neigh[nex]) == 2:
			#print(nex)
			nums[nex] = val
			val += 1
			for guy in neigh[nex]:
				if guy != old:
					new = guy
			old = nex
			nex = new
		nums[nex] = n - 1
		out = []
		for a, b in edges:
			x = nums[a]
			y = nums[b]
			if x > y:
				x, y = y, x
			if x % 2 == 0:
				out.append(2)
			else:
				out.append(3)
		print(*out)