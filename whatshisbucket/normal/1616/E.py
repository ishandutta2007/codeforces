import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

class Segtree():
	def __init__(self, start, end):
		self.count = 0
		self.start = start
		self.end = end
		self.left = None
		self.right = None
		self.mid = None
		if end - start > 1:
			self.mid = (start + end) // 2
			self.left = Segtree(start, self.mid)
			self.right = Segtree(self.mid, end)
			self.count = self.left.count + self.right.count
		else:
			self.count = 0

	def update(self, ind):
		self.count += 1
		if self.mid is not None:
			if ind < self.mid:
				self.left.update(ind)
			else:
				self.right.update(ind)

	def after(self, ind):
		if ind == self.start:
			#print(self.start, self.end, self.count)
			return self.count
		if ind == self.end:
			#print(self.start, self.end, 0)
			return 0
		if ind < self.mid:
			x = self.right.count + self.left.after(ind)
			#print(self.start, self.end, x)
			return x
		#print(self.start, self.end, self.right.after(ind))
		return self.right.after(ind)

t, = I()
for _ in range(t):
	n, = I()
	s = sys.stdin.readline().strip()
	t = sys.stdin.readline().strip()
	if s < t:
		print(0)
		continue
	locs = {char:[] for char in 'abcdefghijklmnopqrstuvwxyz'}
	for i in range(n):
		locs[s[i]].append(i)

	moved = Segtree(0, n)
	#moved.update(2)
	#print(moved.after(1))

	used = 0
	best = float('inf')
	alpha = 'abcdefghijklmnopqrstuvwxyz'
	for char in alpha:
		locs[char] = locs[char][::-1]
	for i in range(n):
		if used > best:
			break
		c = t[i]
		close = n
		for char in alpha:
			if char < c:
				if locs[char] != [] and locs[char][-1] < close:
					close = locs[char][-1]
			else:
				break
		if close < n:
			steps = close - i + moved.after(close)
			#print(i, steps)
			#print(i, used + steps)
			best = min(best, used + steps)

		if len(locs[c]) > 0:
			ind = locs[c][-1]
			locs[c].pop(-1)
			used += ind - i + moved.after(ind)
			#print(used)
			moved.update(ind)
		else:
			break
	if best < float('inf'):
		print(best)
	else:
		print(-1)