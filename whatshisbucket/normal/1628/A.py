import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	suffmex = [0] * n
	found = [0] * (n + 1)
	ind = 0
	for i in range(n - 1, -1, -1):
		found[a[i]] += 1
		while found[ind]:
			ind += 1
		suffmex[i] = ind

	b = []
	i = 0
	while i < n:
		x = suffmex[i]
		if x == 0:
			while i < n:
				b.append(0)
				i += 1
			break
		b.append(x)
		seen = [0] * x
		zeroes = x
		while zeroes:
			if a[i] < x:
				if seen[a[i]] == 0:
					seen[a[i]] = 1
					zeroes -= 1
			i += 1

	print(len(b))
	print(*b)