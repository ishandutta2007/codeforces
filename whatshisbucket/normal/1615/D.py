import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
prin = sys.stdout.write

t, = I()
for _ in range(t):
	n, m = I()
	edges = []
	same = {i:[] for i in range(n)}
	diff = {i:[] for i in range(n)}
	for i in range(n - 1):
		x, y, v = I()
		edges.append((x, y, v))
		if v >= 0:
			par = bin(v)[2:].count('1') % 2
			if par == 0:
				same[x - 1].append(y - 1)
				same[y - 1].append(x - 1)
			else:
				diff[x - 1].append(y - 1)
				diff[y - 1].append(x - 1)
	for i in range(m):
		a, b, p = I()
		if p == 0:
			same[a - 1].append(b - 1)
			same[b - 1].append(a - 1)
		else:
			diff[a - 1].append(b - 1)
			diff[b - 1].append(a - 1)

	covered = [-1] * n
	bad = False
	for i in range(n):
		if covered[i] == -1 and not bad:
			layer = [i]
			covered[i] = 0
			while layer != [] and not bad:
				newlayer = []
				for guy in layer:
					x = covered[guy]
					for boi in same[guy]:
						if covered[boi] == 1 - x:
							bad = True
						elif covered[boi] == -1:
							covered[boi] = x
							newlayer.append(boi)
					for boi in diff[guy]:
						if covered[boi] == x:
							bad = True
						elif covered[boi] == -1:
							covered[boi] = 1 - x
							newlayer.append(boi)
				layer = newlayer
	if bad:
		prin("NO\n")
	else:
		prin("YES\n")
		for x, y, v in edges:
			if v >= 0:
				prin(' '.join([str(x), str(y), str(v)]) + '\n')
			else:
				if covered[x - 1] == covered[y - 1]:
					prin(' '.join([str(x), str(y), '0']) + '\n')
				else:
					prin(' '.join([str(x), str(y), '1']) + '\n')