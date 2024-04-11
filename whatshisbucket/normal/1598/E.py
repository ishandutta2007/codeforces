class SplayTree():
	def __init__(self):
		self.children={}
		self.parents={}
		self.root=None
	def insert(self, x):
		if self.root is None:
			self.root=x
			self.children[x]=[None,None]
			self.parents[x]=None
		else:
			curr = self.root
			while True:
				if curr == x:
					self.splay(x)
					return None
				elif x < curr:
					if self.children[curr][0] is None:
						self.children[curr][0] = x
						self.children[x] = [None, None]
						self.parents[x] = curr
						self.splay(x)
						return None
					else:
						curr = self.children[curr][0]
				else:
					if self.children[curr][1] is None:
						self.children[curr][1] = x
						self.children[x] = [None, None]
						self.parents[x] = curr
						self.splay(x)
						return None
					else:
						curr = self.children[curr][1]
 
	def find(self, x):
		return x in self.parents
 
	def delete(self, x, show=False):
		if self.children[x][0] is None and self.children[x][1] is None:
			if self.root == x:
				self.root = None
			del self.children[x]
			p = self.parents[x]
			del self.parents[x]
			for i in range(2):
				if self.children[p][i] == x:
					self.children[p][i] = None
			self.splay(p)
		elif self.children[x][0] is None or self.children[x][1] is None:
			if self.children[x][0] is None:
				ind = 1
			else:
				ind = 0
			child = self.children[x][ind]
			if self.root == x:
				self.root = child
				del self.children[x]
				del self.parents[x]
				self.parents[child] = None
			else:
				p = self.parents[x]
				self.parents[child] = p
				for i in range(2):
					if self.children[p][i] == x:
						self.children[p][i] = child
				del self.parents[x]
				del self.children[x]
				self.splay(p)
		else:
			s = self.successor(x)
			if self.parents[s] == x:
				skids = self.children[s][:]
				xkid = self.children[x][0]
				xpar = self.parents[x]
				self.children[s] = [xkid, x]
				self.parents[s] = xpar
				self.children[x] = skids
				self.parents[x] = s
				for i in skids:
					if i is not None:
						self.parents[i] = x
				if xkid is not None:
					self.parents[xkid] = s
				if xpar is not None:
					for i in range(2):
						if self.children[xpar][i] == x:
							self.children[xpar][i] = s
				if self.root == x:
					self.root = s
				self.delete(x)
				if xpar is not None:
					self.splay(xpar)
			else:
				skids = self.children[s][:]
				spar = self.parents[s]
				xkids = self.children[x][:]
				xpar = self.parents[x]
				self.children[s] = xkids
				self.parents[s] = xpar
				self.children[x] = skids
				self.parents[x] = spar
				for i in skids:
					if i is not None:
						self.parents[i] = x
				for i in xkids:
					if i is not None:
						self.parents[i] = s
				for i in range(2):
					if spar is not None and self.children[spar][i] == s:
						self.children[spar][i] = x
					if xpar is not None and self.children[xpar][i] == x:
						self.children[xpar][i] = s
				if self.root == x:
					self.root = s
				if show:
					print(self.children)
					print(self.parents)
					print(self.root)
				self.delete(x)
				if xpar is not None:
					self.splay(xpar)
 
	def successor(self,x):
		if self.find(x):
			if self.children[x][1] is None:
				curr = x
				while self.parents[curr] is not None:
					if self.parents[curr] > curr:
						return self.parents[curr]
					curr = self.parents[curr]
				return None 
			else:
				curr = self.children[x][1]
			while self.children[curr][0] is not None:
				curr = self.children[curr][0]
			return curr
		else:
			curr = self.root
			prev = None
			while True:
				if x < curr:
					if self.children[curr][0] is None:
						self.splay(curr)
						return curr
					else:
						prev = curr
						curr = self.children[curr][0]
				else:
					if self.children[curr][1] is None:
						if prev is not None:
							self.splay(prev)
						return prev
					else:
						curr = self.children[curr][1]
	def predecessor(self,x):
		if self.find(x):
			if self.children[x][0] is None:
				curr = x
				while self.parents[curr] is not None:
					if self.parents[curr] < curr:
						return self.parents[curr]
					curr = self.parents[curr]
				return None
			else:
				curr = self.children[x][0]
			while self.children[curr][1] is not None:
				curr = self.children[curr][1]
			return  curr
		else:
			curr = self.root
			prev = None
			while True:
				if x > curr:
					if self.children[curr][1] is None:
						self.splay(curr)
						return curr
					else:
						prev = curr
						curr = self.children[curr][1]
				else:
					if self.children[curr][0] is None:
						if prev is not None:
							self.splay(prev)
						return prev
					else:
						curr = self.children[curr][0]
 
	def splay(self, x):
		while self.parents[x] is not None:
			p = self.parents[x]
			gp = self.parents[p]
			if gp is None:
				if p > x:
					a,b = self.children[x]
					c = self.children[p][1]
					self.children[x] = [a,p]
					self.children[p] = [b,c]
					self.parents[x] = None
					self.parents[p] = x
					self.parents[b] = p
					self.root = x
				else:
					a = self.children[p][0]
					b,c = self.children[x]
					self.children[x] = [p,c]
					self.children[p] = [a,b]
					self.parents[x] = None
					self.parents[p] = x
					self.parents[b] = p
					self.root = x
			else:
				ggp = self.parents[gp]
				if p > x and gp > x:
					a,b = self.children[x]
					c = self.children[p][1]
					d = self.children[gp][1]
					self.children[x] = [a,p]
					self.children[p] = [b,gp]
					self.children[gp] = [c,d]
					self.parents[x] = ggp
					self.parents[p] = x
					self.parents[gp] = p
					self.parents[b] = p
					self.parents[c] = gp
				elif p < x and gp < x:
					c,d = self.children[x]
					b = self.children[p][0]
					a = self.children[gp][0]
					self.children[x] = [p,d]
					self.children[p] = [gp,c]
					self.children[gp] = [a,b]
					self.parents[x] = ggp
					self.parents[p] = x
					self.parents[gp] = p
					self.parents[b] = gp
					self.parents[c] = p
				elif p < x and gp > x:
					b,c = self.children[x]
					a = self.children[p][0]
					d = self.children[gp][1]
					self.children[x] = [p,gp]
					self.children[p] = [a,b]
					self.children[gp] = [c,d]
					self.parents[x] = ggp
					self.parents[p] = x
					self.parents[gp] = x
					self.parents[b] = p
					self.parents[c] = gp
				else:
					b,c = self.children[x]
					d = self.children[p][1]
					a = self.children[gp][0]
					self.children[x] = [gp,p]
					self.children[p] = [c,d]
					self.children[gp] = [a,b]
					self.parents[x] = ggp
					self.parents[p] = x
					self.parents[gp] = x
					self.parents[b] = gp
					self.parents[c] = p
				if ggp is not None:
					for i in range(2):
						if self.children[ggp][i] == gp:
							self.children[ggp][i] = x
				else:
					self.root = x
			if None in self.parents:
				del self.parents[None]
 
 
n,m,q = map(int,input().split())
diag = {}
for i in range(-m,n+1):
	diag[i] = SplayTree()
	diag[i].insert(max(0,i))
	diag[i].insert(min(n+1,m+1+i))
 
total = 0
j = n
k = m
while j>0 and k>0:
	total += 2*j*k
	total += j*(k-1)
	total += k*(j-1)
	j-=1
	k-=1
total -= n*m
for _ in range(q):
	x, y = map(int, input().split())
	diff = x-y
	pred = diag[diff].predecessor(x)
	succ = diag[diff].successor(x)
	predup = diag[diff-1].predecessor(x)
	succup = diag[diff-1].successor(x-1)
	preddown = diag[diff+1].predecessor(x+1)
	succdown = diag[diff+1].successor(x)
	beforeup = min(2*(x-pred)-1,2*(x-predup)-2)
	afterup = min(2*(succ-x)-1,2*(succup-x))
	beforedown = min(2*(x-pred)-1,2*(x-preddown))
	afterdown = min(2*(succ-x)-1,2*(succdown-x)-2)
	change = (beforeup+1)*(afterup+1) + (beforedown+1)*(afterdown+1) - 1
	if diag[diff].find(x):
		total += change
		diag[diff].delete(x)
	else:
		total -= change
		diag[diff].insert(x)
	print(total)