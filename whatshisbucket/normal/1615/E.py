import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
prin = sys.stdout.write
import heapq

n, k = I()
graph = {i: [] for i in range(n)}
for i in range(n - 1):
	u, v = I()
	graph[u - 1].append(v - 1)
	graph[v - 1].append(u - 1)
children = {}
parents = [None] * n
layer = [0]
leaves = 0
while layer != []:
	newlayer = []
	for guy in layer:
		kids = []
		for boi in graph[guy]:
			if boi != parents[guy]:
				newlayer.append(boi)
				kids.append(boi)
				parents[boi] = guy
		children[guy] = kids
		if len(kids) == 0:
			leaves += 1
	layer = newlayer
if leaves <= k:
	red = max(leaves, min(k, n // 2))
	print(red * (n - red))
	exit()
dist = [0] * n
curr = 0
inds = [0] * n
biggest = [0] * n
while curr is not None:
	if inds[curr] >= len(children[curr]):
		if len(children[curr]) == 0:
			dist[curr] = 0
			biggest[curr] = None
		else:
			best = None
			big = -1
			for guy in children[curr]:
				if dist[guy] > big:
					big = dist[guy]
					best = guy
			dist[curr] = big + 1
			biggest[curr] = best
		curr = parents[curr]
	else:
		inds[curr] += 1
		curr = children[curr][inds[curr] - 1]
#print(dist)
#print(biggest)
pq = []
covered = [0] * n
covered[0] = 1
for guy in children[0]:
	heapq.heappush(pq, (-dist[guy], guy))
for i in range(k):
	d, v = heapq.heappop(pq)
	curr = v
	while curr is not None:
		#print(curr)
		covered[curr] = 1
		new = biggest[curr]
		for guy in children[curr]:
			if guy != new:
				heapq.heappush(pq, (-dist[guy], guy))
		curr = new
red = k
blue = n - sum(covered)
while blue - red > n - blue - red:
	blue -= 1
print((n - red - blue) * (red - blue))