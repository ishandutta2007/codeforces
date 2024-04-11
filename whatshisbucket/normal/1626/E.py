import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

n, = I()
c = I()

totblack = sum(c)
neigh = [[] for i in range(n)]
for i in range(n - 1):
	u, v = I()
	neigh[u - 1].append(v - 1)
	neigh[v - 1].append(u - 1)

parents = [-1] * n
parents[0] = None
children = [[] for i in range(n)]
inds = [0] * n
curr = 0
while curr is not None:
	if inds[curr] >= len(neigh[curr]):
		curr = parents[curr]
	else:
		if neigh[curr][inds[curr]] == parents[curr]:
			inds[curr] += 1
		else:
			inds[curr] += 1
			new = neigh[curr][inds[curr] - 1]
			parents[new] = curr
			children[curr].append(new)
			curr = new

blackchild = [0] * n
for i in range(n):
	for guy in children[i]:
		if c[guy]:
			blackchild[i] = 1
			break

order = []
curr = 0
inds = [0] * n
while curr is not None:
	if inds[curr] >= len(children[curr]):
		order.append(curr)
		curr = parents[curr]
	else:
		inds[curr] += 1
		curr = children[curr][inds[curr] - 1]

redro = order[::-1]
black = [0] * n
spec = [0] * n

for v in order:
	tot = 0
	tspec = 0
	for kid in children[v]:
		tot += black[kid]
		tspec += spec[kid]
	if tspec > 0 or (tot > 0 and c[v] > 0) or (tot > 1 and blackchild[v] > 0):
		spec[v] = 1
	tot += c[v]
	black[v] = tot

for i in range(n):
	if c[i]:
		spec[i] = 1
		if parents[i] is not None:
			spec[parents[i]] = 1
		for guy in children[i]:
			spec[guy] = 1

for v in redro:
	if v == 0:
		continue
	vals = sum(black[guy] for guy in children[v])
	if totblack - vals == 1:
		continue
	if spec[parents[v]]:
		spec[v] = 1

print(*spec)