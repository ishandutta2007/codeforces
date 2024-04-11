import sys
inpu = sys.stdin.readline

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	locs = [0] * (n + 1)
	inds = [(a[i], i) for i in range(n)]
	inds.sort(reverse = True)
	curr = 1
	dist = 0
	for count, ind in inds:
		locs[ind + 1] = curr
		dist += 2 * count * abs(curr)
		if curr >= 0:
			curr = - curr
		else:
			curr = 1 - curr
	print(dist)
	print(' '.join(str(guy) for guy in locs))