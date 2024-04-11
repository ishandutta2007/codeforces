input()
g = {0: -1}
z = s = 0
for i, c in enumerate(raw_input()):
	s += 2 * int(c) - 1
	g[s] = p = g.get(s, i)
	z = max(z, i - p)
print z