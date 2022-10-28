# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

import collections
t, = I()
for _ in range(t):
	n, = I()
	a = I()
	b = I()
	a = [val - 1 for val in a]
	b = [val - 1 for val in b]
	freq, occ = collections.Counter(a).most_common(1)[0]
	inds = {}
	bad = False
	for i in range(n):
		if a[i] != b[i]:
			if a[i] in inds:
				inds[a[i]].add(i)
			else:
				inds[a[i]] = {i}
		elif a[i] != freq:
			bad = True
	if bad:
		print('WA')
		continue
	bb = b[:]
	cycles = []
	# print(inds)
	# break
	for i in range(n):
		if a[i] != b[i]:
			cycle = [i]
			curr = i
			while True:
				curr = inds[b[curr]].pop()
				if curr == i:
					break
				cycle.append(curr)
			cycles.append(cycle)
			for j in cycle:
				b[j] = a[j]
	# print(cycles)
	out = [[] for i in range(n)]
	ins = [0] * n
	for cycle in cycles:
		l = len(cycle)
		for i in range(l):
			if a[cycle[i]] != freq and a[cycle[i - 1]] != freq:
				out[a[cycle[i - 1]]].append(a[cycle[i]])
				ins[a[cycle[i]]] += 1
	# print(out)
	# print(ins)
	q = []
	for i in range(n):
		if ins[i] == 0:
			q.append(i)
	qind = 0
	while qind < len(q):
		v = q[qind]
		for v1 in out[v]:
			ins[v1] -= 1
			if ins[v1] == 0:
				q.append(v1)
		qind += 1
	if sum(ins) > 0:
		print('WA')
	else:
		print('AC')