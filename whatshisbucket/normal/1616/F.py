import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

class Equation():
	def __init__(self, variables, val, index, inclusion):
		self.coeffs = {}
		for guy in variables:
			self.coeffs[guy] = 1
			inclusion[guy].add(index)
		self.val = val
		self.index = index

	def add(self, other, inclusion):
		self.val += other.val
		for guy in other.coeffs:
			if guy in self.coeffs:
				x = (self.coeffs[guy] + other.coeffs[guy]) % 3
				if x == 0:
					del self.coeffs[guy]
					inclusion[guy].remove(self.index)
				else:
					self.coeffs[guy] = x
			else:
				self.coeffs[guy] = other.coeffs[guy]
				inclusion[guy].add(self.index)

	def sub(self, other, inclusion):
		self.val -= other.val
		for guy in other.coeffs:
			if guy in self.coeffs:
				if self.coeffs[guy] == other.coeffs[guy]:
					del self.coeffs[guy]
					inclusion[guy].remove(self.index)
				else:
					self.coeffs[guy] = (self.coeffs[guy] - other.coeffs[guy]) % 3
			else:
				self.coeffs[guy] = 3 - other.coeffs[guy]
				inclusion[guy].add(self.index)

t, = I()
for _ in range(t):
	n, m = I()
	neigh = [{} for i in range(n)]
	colors = []
	for i in range(m):
		a, b, c = I()
		a -= 1
		b -= 1
		if c > 0:
			c -= 1
		colors.append(c)
		if a < b:
			neigh[a][b] = (c, i)
		else:
			neigh[b][a] = (c, i)

	triangles = []
	for i in range(n):
		for j in range(i + 1, n):
			for k in range(j + 1, n):
				if j in neigh[i] and k in neigh[i] and k in neigh[j]:
					triangles.append((i, j, k))

	equations = []
	l = 0
	inclusion = [set() for i in range(m)]
	for i, j, k in triangles:
		c1, i1 = neigh[i][j]
		c2, i2 = neigh[i][k]
		c3, i3 = neigh[j][k]
		variables = []
		val = 0
		if c1 == -1:
			variables.append(i1)
		else:
			val -= c1
		if c2 == -1:
			variables.append(i2)
		else:
			val -= c2
		if c3 == -1:
			variables.append(i3)
		else:
			val -= c3
		equations.append(Equation(variables, val % 3, l, inclusion))
		l += 1

	pivots = set()
	pivotvars = set()
	for i in range(m):
		add = False
		for j in inclusion[i] - pivots:
			pivot = j
			add = True
			pivotvars.add(i)
			l = list(inclusion[i])
			main = equations[j]
			coeff = main.coeffs[i]
			for k in l:
				if k != j:
					o = equations[k].coeffs[i]
					if o == coeff:
						equations[k].sub(main, inclusion)
					else:
						equations[k].add(main, inclusion)
			break
		if add:
			pivots.add(pivot)

	for guy in equations:
		if len(guy.coeffs) == 0 and guy.val % 3 != 0:
			print(-1)
			break
	else:
		for i in range(m - 1, -1, -1):
			if i not in pivotvars and colors[i] == -1:
				colors[i] = 0
			elif i in pivotvars:
				#print(i)
				for j in inclusion[i]:
					eq = equations[j]
					val = eq.val
					for v in eq.coeffs:
						if v != i:
							val -= eq.coeffs[v] * colors[v]
					if eq.coeffs[i] == 1:
						colors[i] = val % 3
					else:
						colors[i] = (-val) % 3
		colors = [guy + 1 for guy in colors]
		print(*colors)