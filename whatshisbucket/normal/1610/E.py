import sys
inpu = sys.stdin.readline

def find(k, l):
	start = 0
	end = len(l) - 1
	while end > start:
		curr = (start + end) // 2
		if l[curr] >= k:
			end = curr
		elif l[curr] < k:
			start = curr + 1
	return l[start]

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	unique = [a[0]]
	counts = [1]
	for i in range(1, n):
		if a[i] == unique[-1]:
			counts[-1] += 1
		else:
			unique.append(a[i])
			counts.append(1)

	big = unique[-1]
	best = 0
	for i in range(len(unique)):
		start = unique[i]
		tot = counts[i]
		if i < len(unique) - 1:
			curr = unique[i + 1]
			tot += 1
			nex = 2 * curr - start
			while nex <= big:
				curr = find(nex, unique)
				tot += 1
				nex = 2 * curr - start
		if tot > best:
			best = tot
	print(n - best)