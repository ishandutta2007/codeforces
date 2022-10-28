import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	b = I()
	diffs = [abs(a[i] - b[i]) for i in range(n)]

	poss = []
	poss.append({0: None})
	for i in range(n):
		new = {}
		for guy in poss[-1]:
			new[guy + diffs[i]] = 1
			new[guy - diffs[i]] = -1
		poss.append(new)

	sml = float('inf')
	for guy in poss[-1]:
		sml = min(sml, abs(guy))

	if sml in poss[-1]:
		curr = sml
	else:
		curr = -sml
	newdiffs = []
	for i in range(n, 0, -1):
		if poss[i][curr] == 1:
			newdiffs.append(diffs[i - 1])
			curr -= diffs[i - 1]
		else:
			newdiffs.append(-diffs[i - 1])
			curr += diffs[i - 1]
	newdiffs = newdiffs[::-1]

	newa = []
	newb = []
	for i in range(n):
		sml = min(a[i], b[i])
		big = max(a[i], b[i])
		if newdiffs[i] < 0:
			newa.append(sml)
			newb.append(big)
		else:
			newa.append(big)
			newb.append(sml)

	cost = 0
	for i in range(n):
		for j in range(i + 1, n):
			cost += (newa[i] + newa[j]) ** 2
			cost += (newb[i] + newb[j]) ** 2
	print(cost)