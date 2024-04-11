import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

class UnionFind():
	def __init__(self, n, sml = True):
		self.parents = [None] * n
		self.sizes = [1] * n
		self.safe = [0] * n
		self.rvals = [float('inf')] * n
		self.lvals = [-float('inf')] * n
		self.lefts = [i for i in range(n)]
		self.rights = [i for i in range(n)] 

	def find(self, i):
		path = []
		curr = i
		while self.parents[curr] is not None:
			path.append(curr)
			curr = self.parents[curr]

		for x in path:
			self.parents[x] = curr
		return curr

	def union(self, x, y):
		xpath = []
		ypath = []
		xcurr = x
		while self.parents[xcurr] is not None:
			xpath.append(xcurr)
			xcurr = self.parents[xcurr]
		ycurr = y
		while self.parents[ycurr] is not None:
			ypath.append(ycurr)
			ycurr = self.parents[ycurr]
		if xcurr == ycurr:
			return None
		if self.sizes[xcurr] < self.sizes[ycurr]:
			self.parents[xcurr] = ycurr
			self.sizes[ycurr] += self.sizes[xcurr]
			self.safe[ycurr] = max(self.safe[xcurr], self.safe[ycurr])
			self.lefts[ycurr] = min(self.lefts[ycurr], self.lefts[xcurr])
			self.rights[ycurr] = max(self.rights[ycurr], self.rights[xcurr])
			self.rvals[ycurr] = min(self.rvals[ycurr], self.rvals[xcurr])
			self.lvals[ycurr] = max(self.lvals[ycurr], self.lvals[xcurr])
			for guy in xpath:
				self.parents[guy] = ycurr
			for guy in ypath:
				self.parents[guy] = ycurr
		else:
			self.parents[ycurr] = xcurr
			self.sizes[xcurr] += self.sizes[ycurr]
			self.safe[xcurr] = max(self.safe[xcurr], self.safe[ycurr])
			self.lefts[xcurr] = min(self.lefts[xcurr], self.lefts[ycurr])
			self.rights[xcurr] = max(self.rights[xcurr], self.rights[ycurr])
			self.rvals[xcurr] = min(self.rvals[xcurr], self.rvals[ycurr])
			self.lvals[xcurr] = max(self.lvals[xcurr], self.lvals[ycurr])
			for guy in xpath:
				self.parents[guy] = xcurr
			for guy in ypath:
				self.parents[guy] = xcurr

n, qq = I()
right = UnionFind(n)

out = []
for i in range(qq):
	#print(right.parents, right.sizes, right.vals)
	#print(left.parents, left.sizes, left.vals)
	q = I()
	if q[0] == 0:
		l = q[1] - 1
		r = q[2] - 1
		if q[-1] == 0:
			ind = r
			while ind >= l:
				x = right.find(r)
				right.safe[x] = 1
				y = right.find(ind)
				if x == y:
					ind = right.lefts[x] - 1
				else:
					right.union(x, y)
			if l > 0:
				ppp = right.find(l - 1)
				if right.safe[ppp]:
					right.union(r, ppp)
			if r < n - 1:
				ppp = right.find(r + 1)
				if right.safe[ppp]:
					right.union(r, ppp)
		else:
			x = right.find(l)
			right.rvals[x] = min(right.rvals[x], r)
			y = right.find(r)
			right.lvals[y] = max(right.lvals[y], l)
	else:
		ind = q[-1] - 1
		p = right.find(ind)
		if right.safe[p]:
			out.append('NO')
		else:
			sml = right.rvals[p]
			if ind > 0:
				pp = right.find(ind - 1)
				if right.safe[pp]:
					sml = min(sml, right.rvals[pp])
			if sml < n:
				pleft = right.find(sml)
				if right.lefts[pleft] == ind or (right.safe[pleft] and right.lefts[pleft] == ind + 1):
					out.append('YES')
				else:
					out.append('N/A')
			else:
				out.append('N/A')

print('\n'.join(out))