import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	a.sort()
	x = [0]
	curr = a[0]
	ct = 0
	for guy in a:
		if guy != curr:
			add = x[-1]
			for i in range(ct - 1):
				x.append(add)
			x.append(len(x))
			curr = guy
			ct = 1
		else:
			ct += 1
	add = x[-1]
	for i in range(ct - 1):
		x.append(add)
	x.append(len(x))
	i = 1
	best = float('inf')
	bi = 0
	bj = 0
	while i <= n:
		j = 1
		first = x[i]
		while j <= n:
			if first + j > n:
				second = n - first
			else:
				second = x[first + j] - first
			rest = max(n - first - second, 0)
			xx = 1 << (len(bin(rest)) - 2)
			if xx >= 2 * rest:
				xx //= 2
			tot = i + j + xx
			if tot < best:
				best = tot
				bi = i
				bj = j
			j *= 2
		i *= 2
	print(best - n)