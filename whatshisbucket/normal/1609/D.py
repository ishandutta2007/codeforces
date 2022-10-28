import sys
import collections
inpu = sys.stdin.readline
prin = sys.stdout.write

n,d = map(int, inpu().split())
add = []
for i in range(d):
	a, b = map(int, inpu().split())
	add.append((a - 1, b - 1))
sets = [i for i in range(n)]
free = 0
for i in range(d):
	a, b = add[i]
	kill = sets[b]
	replace = sets[a]
	if kill != replace:
		for i in range(n):
			if sets[i] == kill:
				sets[i] = replace
	else:
		free += 1
	c = collections.Counter(sets)
	l = c.most_common(free + 1)
	print(sum(guy[1] for guy in l) - 1)