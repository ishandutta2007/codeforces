import sys
inpu = sys.stdin.readline
prin = sys.stdout.write
t = int(inpu())

def adj(r, c, mat):
	# UDLR
	out = [0, 0, 0, 0]
	if r > 0:
		if mat[r - 1][c] == '.':
			out[0] = 1
	if r < len(mat) - 1:
		if mat[r + 1][c] == '.':
			out[1] = 1
	if c > 0:
		if mat[r][c - 1] == '.':
			out[2] = 1
	if c < len(mat[0]) - 1:
		if mat[r][c + 1] == '.':
			out[3] = 1
	return out
for _ in range(t):
	n, m = map(int, inpu().split())
	strs = []
	for i in range(n):
		s = [*inpu()]
		if "L" in s:
			lab = (i, s.index('L'))
		strs.append(s)
	layer = [lab]
	while layer != []:
		newlayer = []
		for r, c in layer:
			a = adj(r, c, strs)
			if a[0] and strs[r - 1][c] == '.':
				b = sum(adj(r - 1, c, strs))
				if b < 2:
					newlayer.append((r - 1, c))
					strs[r - 1][c] = '+'
			if a[1] and strs[r + 1][c] == '.':
				b = sum(adj(r + 1, c, strs))
				if b < 2:
					newlayer.append((r + 1, c))
					strs[r + 1][c] = '+'
			if a[2] and strs[r][c - 1] == '.':
				b = sum(adj(r, c - 1, strs))
				if b < 2:
					newlayer.append((r, c - 1))
					strs[r][c - 1] = '+'
			if a[3] and strs[r][c + 1] == '.':
				b = sum(adj(r, c + 1, strs))
				if b < 2:
					newlayer.append((r, c + 1))
					strs[r][c + 1] = '+'

		layer = newlayer
	for guy in strs:
		prin(''.join(guy))