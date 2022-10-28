# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	b = I()
	a = [guy - 1 for guy in a]
	b = [guy - 1 for guy in b]
	locs = [0] * n
	for i in range(n):
		locs[a[i]] = i
	covered = [0] * n
	used = 0
	fun = 0
	for i in range(n):
		if not covered[i]:
			cycle = []
			curr = i
			go = True
			while curr != i or go:
				covered[curr] = 1
				go = False
				cycle.append(curr)
				curr = locs[b[curr]]
			old = used
			used += len(cycle) // 2
			new = used
			size = len(cycle) - len(cycle) % 2
			avg = n - old - new
			fun += size * avg
	print(fun)