import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

class unionfind():
	def __init__(self, n):
		self.size = [1] * n
		self.parent = [None] * n
		self.rep = [i for i in range(n)]

	def find(self, x):
		path = []
		curr = x
		while self.parent[curr] is not None:
			path.append(curr)
			curr = self.parent[curr]
		for guy in path:
			self.parent[guy] = curr
		return curr

	def union(self, x, y):
		currx = self.find(x)
		curry = self.find(y)
		if currx == curry:
			return None
		if self.size[currx] < self.size[curry]:
			self.parent[currx] = curry
			self.size[curry] += self.size[currx]
			self.rep[curry] = max(self.rep[currx], self.rep[curry])
		else:
			self.parent[curry] = currx
			self.size[currx] += self.size[curry]
			self.rep[currx] = max(self.rep[currx], self.rep[curry])

n, = I()
p = I()
for i in range(n):
	p[i] -= 1
a = I()
for i in range(n):
	a[i] -= 1
m = max(a)
l = n - len(set(p))
rounds = (m - n + 1) // l

perms = [p]
for i in range(len(bin(rounds)) - 3):
	prev = perms[-1]
	new = [prev[prev[i]] for i in range(n)]
	perms.append(new)

curr = [i for i in range(n)]
for i in range(len(perms)):
	if rounds >> i & 1:
		new = [perms[i][curr[j]] for j in range(n)]
		curr = new

smls = {}
firsts = {}
for i in range(n):
	if curr[i] not in smls:
		smls[curr[i]] = a[curr[i]]
		firsts[curr[i]] = i
dsf = unionfind(n)
perm = [-1] * n

for guy in firsts:
	perm[firsts[guy]] = smls[guy]
	if smls[guy] + 1 < n:
		dsf.union(smls[guy], smls[guy] + 1)

for i in range(n):
	if perm[i] == -1:
		x = smls[curr[i]]
		y = dsf.find(x)
		use = dsf.rep[y]
		perm[i] = use
		if use + 1 < n:
			dsf.union(y, use + 1)

perm = [guy + 1 for guy in perm]
print(*perm)