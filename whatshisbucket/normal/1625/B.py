import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	first = {}
	for i in range(n):
		if a[i] not in first:
			first[a[i]] = [i]
		else:
			first[a[i]].append(i)
	best = n + 1
	for guy in first:
		l = first[guy]
		for i in range(len(l) - 1):
			if l[i + 1] - l[i] < best:
				best = l[i + 1] - l[i]

	print(n - best)