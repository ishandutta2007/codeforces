import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def mergeinv(l):
	if len(l) == 1:
		return [0, l]
	mid = len(l) // 2
	x, l1 = mergeinv(l[:mid])
	y, l2 = mergeinv(l[mid:])
	ind1 = 0
	ind2 = 0
	out = []
	invs = x + y
	while ind1 < len(l1) or ind2 < len(l2):
		if ind1 == len(l1):
			out.append(l2[ind2])
			ind2 += 1
		elif ind2 == len(l2):
			out.append(l1[ind1])
			invs += ind2
			ind1 += 1
		else:
			if l1[ind1] < l2[ind2]:
				out.append(l1[ind1])
				invs += ind2
				ind1 += 1
			else:
				out.append(l2[ind2])
				ind2 += 1
	return [invs, out]
t, = I()
for _ in range(t):
	n, = I()
	p = I()
	invs, x = mergeinv(p)
	c = [0] * n
	for i in range(n):
		c[i] = i + 2 - 2 * p[i]
	c.sort(reverse = True)
	s = 0
	out = [invs]
	for i in range(n):
		s += c[i]
		out.append(invs - s - i * (i + 1) // 2)
	print(*out)