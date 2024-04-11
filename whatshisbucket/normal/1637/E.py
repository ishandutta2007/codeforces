# import sys
# I = lambda: [*map(int, sys.stdin.readline().split())]

import io,os
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda: [*map(int, read.readline().split())]

t, = I()
for _ in range(t):
	n, m = I()
	a = I()
	bad = set()
	for i in range(m):
		x, y = I()
		bad.add((x, y))
		bad.add((y, x))

	counts = {}
	for guy in a:
		if guy in counts:
			counts[guy] += 1
		else:
			counts[guy] = 1

	vals = [[] for i in range(n)]
	for guy in counts:
		vals[counts[guy]].append(guy)

	for i in range(n):
		vals[i].sort(reverse = True)

	occupied = []
	for i in range(n):
		if vals[i]:
			occupied.append(i)
	#print(vals)
	#print(occupied)

	bbest = 0
	for ii in range(len(occupied)):
		i = occupied[ii]
		for jj in range(ii + 1, len(occupied)):
			j = occupied[jj]
			cnts = i + j
			best = 0
			indi = 0
			bigj = vals[j][0]
			while indi < len(vals[i]) and vals[i][indi] + bigj > best:
				x = vals[i][indi]
				indj = 0
				while indj < len(vals[j]) and (x, vals[j][indj]) in bad:
					indj += 1
				if indj < len(vals[j]):
					best = max(best, x + vals[j][indj])
				indi += 1
			#print(i, j, best)
			bbest = max(cnts * best, bbest)

	for ii in range(len(occupied)):
		i = occupied[ii]
		if len(vals[i]) > 1:
			cnts = 2 * i
			best = 0
			indi = 0
			while indi < len(vals[i]) - 1 and vals[i][indi] + vals[i][indi + 1] > best:
				x = vals[i][indi]
				indj = indi + 1
				while indj < len(vals[i]) and (x, vals[i][indj]) in bad:
					indj += 1
				if indj < len(vals[i]):
					best = max(best, x + vals[i][indj])
				indi += 1
			#print(i, best)
			bbest = max(cnts * best, bbest)

	print(bbest)