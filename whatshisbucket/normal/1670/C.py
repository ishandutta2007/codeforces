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
	c = I()
	a = [guy - 1 for guy in a]
	b = [guy - 1 for guy in b]
	cverts = [0 for i in range(n)]
	overts = [[] for i in range(n)]
	for i in range(n):
		cverts[i] = [a[i], b[i]]
		overts[a[i]].append(i)
		overts[b[i]].append(i)
	power = 0
	seen = [0] * n
	for i in range(n):
		if not seen[i]:
			cycle = [i]
			go = True
			curr = i
			prev = cverts[i][1]
			while go or curr != i:
				go = False
				sseen = False
				for guy in cverts[curr]:
					if guy != prev or sseen:
						nex = guy
					else:
						sseen = True
				cycle.append(nex)
				prev = curr
				curr = nex
				sseen = False
				for guy in overts[curr]:
					if guy != prev or sseen:
						nex = guy
					else:
						sseen = True
				cycle.append(nex)
				prev = curr
				curr = nex
				seen[curr] = 1
			if len(cycle) > 3:
				for i in range(0, len(cycle), 2):
					if c[cycle[i]] > 0:
						break
				else:
					power += 1
	print(pow(2, power, 1000000007))