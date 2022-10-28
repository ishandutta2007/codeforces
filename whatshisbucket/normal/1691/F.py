# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

M = 10 ** 9 + 7

n, k = I()

binomk = [0] * k
binomk.append(1)
for i in range(k + 1, n + 1):
	binomk.append(binomk[-1] * i * pow(i - k, M - 2, M) % M)
neighbors = [[] for i in range(n)]
for i in range(n - 1):
	a, b = I()
	a -= 1
	b -= 1
	neighbors[a].append(b)
	neighbors[b].append(a)
parents = [None] + [-1] * (n - 1)
children = [[] for i in range(n)]
layer = [0]
while layer:
	newlayer = []
	for guy in layer:
		for boi in neighbors[guy]:
			if boi != parents[guy]:
				children[guy].append(boi)
				parents[boi] = guy
				newlayer.append(boi)
	layer = newlayer
size = [0] * n
q = []
for i in range(n):
	if len(children[i]) == 0:
		q.append(i)
qind = 0
left = [len(children[i]) for i in range(n)]
while qind < len(q):
	v = q[qind]
	tot = 1
	for guy in children[v]:
		tot += size[guy]
	size[v] = tot
	if parents[v] is None:
		break
	left[parents[v]] -= 1
	if left[parents[v]] == 0:
		q.append(parents[v])
	qind += 1

answer = 0
for i in range(n):
	things = []
	for guy in children[i]:
		things.append(size[guy])
	if i != 0:
		things.append(n - 1 - sum(things))
	bins = [binomk[i] for i in things]
	ss = sum(bins) % M
	for guy in things:
		answer = (answer + (n - guy) * guy * binomk[n - guy]) % M
		answer = (answer - (n - guy) * guy * (ss - binomk[guy])) % M
	answer = (answer + n * binomk[n]) % M
	answer = (answer - ss * n) % M
print(answer)