import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

import heapq
t, = I()
for _ in range(t):
	n, k = I()
	wup = [[0] * (k + 1) for i in range(k // 2 + 1)]
	wleft = [[0] * (k + 1) for i in range(k // 2 + 1)]
	wright = [[0] * (k + 1) for i in range(k // 2 + 1)]
	wdown = [[0] * (k + 1) for i in range(k // 2 + 1)]
	l = k + 1
	for i in range(n):
		r1, c1, r2, c2 = I()
		if c2 > c1:
			if r1 > k // 2:
				r1, c1, r2, c2 = l - r1, l - c2, l - r2, l - c1
			wdown[r1 - 1][c1] += 1
			wup[r1][c1] += 1
		elif c2 < c1:
			if r1 > k // 2:
				r1, c1, r2, c2 = l - r1, l - c2, l - r2, l - c1
			wdown[r1 - 1][c2] += 1
			wup[r1][c2] += 1
		elif r2 > r1:
			if r1 > k // 2 or (r1 == k // 2 and c1 > k // 2):
				r1, c1, r2, c2 = l - r2, l - c1, l - r1, l - c2
			wright[r1][c1 - 1] += 1
			wleft[r1][c1] += 1
		else:
			if r2 > k // 2 or (r2 == k // 2 and c1 > k // 2):
				r1, c1, r2, c2 = l - r2, l - c1, l - r1, l - c2
			wright[r2][c1 - 1] += 1
			wleft[r2][c1] += 1

	for i in range(k // 2):
		wdown[k // 2][i] = wup[k // 2][- i - 1]

	dists = [[float('inf')] * (k + 1) for i in range(k // 2 + 1)]
	q = [(0, k // 2, k // 2)]
	while q:
		dist, r, c = heapq.heappop(q)
		if dist >= dists[r][c]:
			continue
		else:
			dists[r][c] = dist
		if r > 0:
			dup = dist + wup[r][c]
			if dup < dists[r - 1][c]:
				heapq.heappush(q, (dup, r - 1, c))

		ddown = dist + wdown[r][c]
		if r == k // 2 - 1 and c > k // 2:
			downr = r + 1
			downc = k - c
		elif r == k // 2 and c < k // 2:
			downr = r - 1
			downc = k - c
		else:
			downr = r + 1
			downc = c
		if downr <= k // 2:
			if ddown < dists[downr][downc]:
				heapq.heappush(q, (ddown, downr, downc))

		if c > 0:
			dleft = dist + wleft[r][c]
			if dleft < dists[r][c - 1]:
				heapq.heappush(q, (dleft, r, c - 1))

		if c < k and (c != k // 2 or r != k // 2):
			dright = dist + wright[r][c]
			if dright < dists[r][c + 1]:
				heapq.heappush(q, (dright, r, c + 1))

	sml = min(dists[0])
	for i in range(k // 2 + 1):
		sml = min(sml, dists[i][0])
	for i in range(k // 2):
		sml = min(sml, dists[i][-1])
	print(n - sml)