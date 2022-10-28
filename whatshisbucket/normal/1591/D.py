import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	if len(set(a)) < n:
		print('yes')
		continue
	inds = {}
	b = sorted(a)
	for i in range(n):
		inds[a[i]] = i
	swaps = 0
	for j in range(n):
		if a[j] != b[j]:
			swaps += 1
			loc = inds[b[j]]
			inds[a[j]] = loc
			inds[a[loc]] = j
			a[j], a[loc] = a[loc], a[j]
	print('yes' if swaps % 2 == 0 else 'no')