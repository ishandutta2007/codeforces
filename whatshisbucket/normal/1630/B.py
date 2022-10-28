import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	a = I()
	a = [guy - 1 for guy in a]
	count = [0] * n
	for guy in a:
		count[guy] += 1

	best = (-1, n)
	tot = count[0]
	x = 0
	y = 0
	need = n // 2 + k // 2
	if n % 2 == 1 or k % 2 == 1:
		need += 1
	while True:
		if tot < need:
			y += 1
			if y == n:
				break
			tot += count[y]
		else:
			if y - x < best[1] - best[0]:
				best = (x, y)
			tot -= count[x]
			x += 1

	x, y = best
	curr = 0
	last = -1
	out = []
	for i in range(n):
		if x <= a[i] <= y:
			curr += 1
		else:
			curr -= 1
		if curr > 0:
			out.append((last + 1, i))
			curr = 0
			last = i

	out = out[:k]
	out[-1] = (out[-1][0], n - 1)
	print(x + 1, y + 1)
	for guy in out:
		print(guy[0] + 1, guy[1] + 1)