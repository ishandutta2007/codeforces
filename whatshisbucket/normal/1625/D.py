import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def stuff(x, bit, a):
	if bit < 0:
		return set(a)
	if len(a) <= 1:
		return set(a)
	a1 = []
	a2 = []
	for guy in a:
		if guy >> bit & 1:
			a1.append(guy)
		else:
			a2.append(guy)
	if x >> bit & 1:
		return stuff1(x, bit - 1, a1, a2)
	else:
		return stuff(x, bit - 1, a1) | stuff(x, bit - 1, a2)

def stuff1(x, bit, a, b):
	if len(a) == 0:
		if len(b) == 0:
			return set()
		return {b[0]}
	if len(b) == 0:
		return {a[0]}
	if bit < 0:
		return {a[0], b[0]}
	if len(a) == 1:
		m = (1 << bit + 1)
		xp = x % m
		for guy in b:
			if (a[0] ^ guy) % m >= xp:
				return {a[0], guy}
		return {a[0]}
	if len(b) == 1:
		m = (1 << bit + 1)
		xp = x % m
		for guy in a:
			if (b[0] ^ guy) % m >= xp:
				return set((b[0], guy))
		return {b[0]}
	a0 = []
	a1 = []
	b0 = []
	b1 = []
	for guy in a:
		if guy >> bit & 1:
			a1.append(guy)
		else:
			a0.append(guy)
	for guy in b:
		if guy >> bit & 1:
			b1.append(guy)
		else:
			b0.append(guy)
	if x >> bit & 1:
		c = stuff1(x, bit - 1, a0, b1)
		d = stuff1(x, bit - 1, a1, b0)
		if len(c) > len(d):
			return c
		return d
	else:
		if a0 and b1:
			return {a0[0], b1[0]}
		if b0 and a1:
			return {b0[0], a1[0]}
		else:
			c = stuff1(x, bit - 1, a0, b0)
			d = stuff1(x, bit - 1, a1, b1)
			if len(c) > len(d):
				return c
			else:
				return d



n, k = I()
a = I()
if k == 0:
	print(n)
	print(*[i + 1 for i in range(n)])
else:
	l = stuff(k, 29, a)
	inds = []
	for i in range(n):
		if a[i] in l:
			inds.append(i + 1)
			l.remove(a[i])
	if len(inds) > 1:
		print(len(inds))
		print(*inds)
	else:
		print(-1)