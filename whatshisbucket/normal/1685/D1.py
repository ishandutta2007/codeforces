# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	p = I()
	p = [guy - 1 for guy in p]
	cycles = []
	hit = [0] * n
	for i in range(n):
		if not hit[i]:
			cycle = {i}
			hit[i] = 1
			nex = p[i]
			while nex not in cycle:
				hit[nex] = 1
				cycle.add(nex)
				nex = p[nex]
			cycles.append(cycle)
	base = cycles[0]
	for i in range(n):
		if i not in base:
			for j in range(len(cycles)):
				if i in cycles[j]:
					break
			base |= cycles[j]
			for j in range(n):
				if p[j] == i:
					p[j] = i - 1
				elif p[j] == i - 1:
					p[j] = i
	q = [0]
	for i in range(n - 1):
		for j in range(n):
			if p[j] == q[-1]:
				q.append(j)
				break
	print(*[guy + 1 for guy in q])