# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	counts = [0] * (n + 1)
	cycles = []
	for i in range(n):
		val = a[i]
		ind = counts[val]
		if len(cycles) <= ind:
			cycles.append([i])
		else:
			cycles[ind].append(i)
		counts[val] += 1

	new = [0] * n
	for cycle in cycles:
		cycle.sort(key = lambda x:a[x])
		l = len(cycle)
		for i in range(l):
			new[cycle[i - 1]] = a[cycle[i]]
	print(*new)