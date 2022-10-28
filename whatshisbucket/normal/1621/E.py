import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

def next(l, val):
	if val > l[-1]:
		return len(l)
	sml = 0
	big = len(l)
	while big - sml > 1:
		mid = (big + sml) // 2
		if l[mid] >= val:
			big = mid
		else:
			sml = mid
	return big

t, = I()
for _ in range(t):
	n, m = I()
	teach = sorted(I())[-m:]
	groups = []
	avgs = []
	for i in range(m):
		k, = I()
		group = I()
		groups.append(group)
		avgs.append((sum(group) / k, i))
	avgs.sort()
	highest = [-1] * m
	right = []
	bad = []
	notleft = []
	for i in range(m):
		if avgs[i][0] > teach[i] + .000001:
			if i == m - 1 or avgs[i][0] > teach[i + 1] + .000001:
				bad.append(i)
			else:
				right.append(i)
		elif i == 0 or avgs[i][0] > teach[i - 1] + .000001:
			notleft.append(i)
	if len(bad) == 1:
		i = bad[0]
		if i == m - 1:
			if len(right) == 0:
				sml = m - 1
			else:
				sml = right[0]
			highest[avgs[i][1]] = teach[sml]
	elif len(bad) == 0:
		if len(right) > 0:
			for i in range(right[-1], m):
				highest[avgs[i][1]] = teach[right[0]]
		else:
			for i in range(m):
				j = next(notleft, i + 1)
				if j == len(notleft):
					highest[avgs[i][1]] = teach[-1]
				else:
					highest[avgs[i][1]] = teach[notleft[j] - 1]

	out = []
	for i in range(m):
		group = groups[i]
		l = len(group)
		h = highest[i]
		if h == -1:
			for j in range(l):
				out.append('0')
		else:
			tot = sum(group)
			for j in range(l):
				if (tot - group[j]) / (l - 1) < h + .000001:
					out.append('1')
				else:
					out.append('0')
	print(''.join(out))