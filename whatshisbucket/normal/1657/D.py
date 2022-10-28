# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())
 
import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

class BIT():
	def __init__(self, a, l, r):
		self.a = a
		self.first = None
		self.l = l
		self.r = r
		self.mid = (l + r) // 2
		if r - l > 1:
			self.left = BIT(a, l, self.mid)
			self.right = BIT(a, self.mid, r)
		else:
			self.left = None
			self.right = None
			units[l] = self

	def update(self, i, val):
		if self.first is None or self.first > i:
			self.first = i
		if self.left is None:
			self.a[i] = val
		elif i < self.mid:
			self.left.update(i, val)
		else:
			self.right.update(i, val)

	def find_next(self, i):
		if i < self.first:
			return self.first
		if i < self.mid:
			x = self.left.find_next(i)
			if x is not None:
				return x
			return self.right.first
		return self.right.find_next(i)

 
n, C = I()
units = []
for i in range(n):
	c, d, h = I()
	units.append((c, d * h))

units.sort(key = lambda x: x[1] / x[0], reverse = True)

values = [0] * (C + 1)
#bit = BIT(values, 0, C + 1)

done = set()
for c, v in units:
	if c in done:
		continue
	for i in range(c, C + 1, c):
		if values[i] == 0:
			values[i] = v * i // c
	done.add(c)

for i in range(1, C + 1):
	values[i] = max(values[i], values[i - 1])

out = []
m, = I()
for i in range(m):
	D, H = I()
	power = D * H
	if power >= values[-1]:
		out.append(-1)
	else:
		sml = 0
		big = C + 1
		while big - sml > 1:
			mid = (big + sml) // 2
			if values[mid] > power:
				big = mid
			else:
				sml = mid
		out.append(big)
print(*out)