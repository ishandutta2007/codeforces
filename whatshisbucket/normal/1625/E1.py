import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, q = I()
s = input()
partial = [0]
vals = {0:[0]}
for i in range(n):
	if s[i] == '(':
		new = partial[-1] + 1
	else:
		new = partial[-1] - 1
	if new in vals:
		vals[new].append(i + 1)
	else:
		vals[new] = [i + 1]
	partial.append(new)

inds = [0] * (n + 1)
for guy in vals:
	l = vals[guy]
	for i in range(len(l)):
		inds[l[i]] = i

ans = {}
for i in range(n, -n - 1, -1):
	if i in vals:
		l = vals[i]
		new = [0]
		for j in range(len(l) - 1):
			x = l[j]
			y = l[j + 1]
			if partial[x + 1] > i:
				l1 = ans[i + 1]
				ix = inds[x + 1]
				iy = inds[y - 1]
				tot = l1[iy] - l1[ix]
				diff = iy - ix
				tot += diff * (diff - 1) // 2
				new.append(new[-1] + tot + 1)
			else:
				new.append(new[-1])
		ans[i] = new

for i in range(q):
	t, l, r = I()
	l -= 1
	val = partial[l]
	a = ans[val]
	ir = inds[r]
	il = inds[l]
	diff = ir - il
	print(a[ir] - a[il] + diff * (diff - 1) // 2)