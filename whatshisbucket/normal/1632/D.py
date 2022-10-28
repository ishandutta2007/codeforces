import sys
I = lambda: [*map(int, sys.stdin.readline().split())]
import math

def gcdsparse(a):
	l = []
	l.append(a)
	c = 1
	while c < len(a):
		new = []
		for i in range(len(a)):
			if i + c < len(l[-1]):
				new.append(math.gcd(l[-1][i], l[-1][i + c]))
			else:
				break
		l.append(new)
		c *= 2
	return l

def partial(table, i, j):
	x = 1
	a = 0
	while 2 * x <= j - i:
		x *= 2
		a += 1
	return math.gcd(table[a][i], table[a][j - x])

n, = I()
a = I()
table = gcdsparse(a)
removed = 0
last = -1
out = []
for i in range(n):
	sml = last + 1
	big = i + 1
	while big - sml > 1:
		mid = (sml + big) // 2
		x = partial(table, mid, i + 1)
		if x < i + 1 - mid:
			sml = mid + 1
		elif x > i + 1 - mid:
			big = mid
		else:
			sml = big = mid
	if partial(table, sml, i + 1) == i + 1 - sml:
		removed += 1
		last = i
	out.append(removed)
print(*out)