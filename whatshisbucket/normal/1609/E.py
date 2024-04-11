import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

class BIT():
	def __init__(self, l, left, right):
		self.bot = left
		self.top = right
		self.mid = (left + right) // 2
		self.l = l
		if right - left == 1:
			self.left = None
			self.right = None
			if l[left] == 'a':
				self.a = 1
				self.b = 0
				self.c = 0
			elif l[left] == 'b':
				self.a = 0
				self.b = 1
				self.c = 0
			else:
				self.a = 0
				self.b = 0
				self.c = 1
			self.ab = 0
			self.bc = 0
			self.abc = 0
		else:
			self.left = BIT(l, left, self.mid)
			self.right = BIT(l, self.mid, right)
			self.a = self.left.a + self.right.a
			self.b = self.left.b + self.right.b
			self.c = self.left.c + self.right.c
			self.ab = min(self.left.a + self.right.ab, self.left.ab + self.right.b)
			self.bc = min(self.left.b + self.right.bc, self.left.bc + self.right.c)
			self.abc = min(self.left.a + self.right.abc, self.left.ab + self.right.bc, self.left.abc + self.right.c)

	def update(self, ind):
		if self.top - self.bot == 1:
			if self.l[ind] == 'a':
				self.a = 1
				self.b = 0
				self.c = 0
			elif self.l[ind] == 'b':
				self.a = 0
				self.b = 1
				self.c = 0
			else:
				self.a = 0
				self.b = 0
				self.c = 1
		else:
			if ind < self.mid:
				self.left.update(ind)
			else:
				self.right.update(ind)
			self.a = self.left.a + self.right.a
			self.b = self.left.b + self.right.b
			self.c = self.left.c + self.right.c
			self.ab = min(self.left.a + self.right.ab, self.left.ab + self.right.b)
			self.bc = min(self.left.b + self.right.bc, self.left.bc + self.right.c)
			self.abc = min(self.left.a + self.right.abc, self.left.ab + self.right.bc, self.left.abc + self.right.c)


n, q = I()
l = [*input()]
b = BIT(l, 0, n)
for i in range(q):
	ind, c = sys.stdin.readline().split()
	ind = int(ind)
	l[ind - 1] = c
	b.update(ind - 1)
	print(b.abc)