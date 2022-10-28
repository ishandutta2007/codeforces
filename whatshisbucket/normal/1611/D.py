t = int(input())
for _ in range(t):
	n = int(input())
	b = list(map(int, input().split()))
	for i in range(n):
		b[i] -= 1
		if b[i] == i:
			root = i
	p = list(map(int, input().split()))
	for i in range(n):
		p[i] -= 1
	weights = [0] * n
	dists = [0] * n
	big = 0
	seen = {root}
	bad = False
	if p[0] == root:
		for i in range(1, n):
			if b[p[i]] in seen:
				dist = dists[b[p[i]]]
				weight = big + 1 - dist
				seen.add(p[i])
				weights[p[i]] = weight
				dists[p[i]] = big + 1
				big += 1
			else:
				bad = True
				break
	else:
		bad = True

	if bad:
		print(-1)
	else:
		print(' '.join(str(guy) for guy in weights))