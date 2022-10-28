t = int(input())
for _ in range(t):
	s = input()
	locs = {}
	for i in range(26):
		locs[s[i]] = i
	w = input()
	dist = 0
	for i in range(len(w) - 1):
		dist += abs(locs[w[i]] - locs[w[i + 1]])
	print(dist)