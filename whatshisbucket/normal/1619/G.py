import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	I()
	n, k = I()
	rows = {}
	cols = {}
	mines = []
	for i in range(n):
		x, y, t = I()
		mines.append((x, y, t))
		if x in cols:
			cols[x].append((y, i, t))
		else:
			cols[x] = [(y, i, t)]
		if y in rows:
			rows[y].append((x, i, t))
		else:
			rows[y] = [(x, i, t)]
	rowind = [-1] * n
	colind = [-1] * n
	for x in cols:
		cols[x].sort()
		for i in range(len(cols[x])):
			colind[cols[x][i][1]] = i
	for y in rows:
		rows[y].sort()
		for j in range(len(rows[y])):
			rowind[rows[y][j][1]] = j
	
	comps = [-1] * n
	short = []
	num = 0
	for i in range(n):
		if comps[i] == -1:
			layer = [i]
			comps[i] = num
			sml = 1000000000
			while layer != []:
				newlayer = []
				for j in layer:
					x, y, t = mines[j]
					sml = min(t, sml)
					ind = rowind[j] - 1
					while ind >= 0 and comps[rows[y][ind][1]] == -1 and rows[y][ind][0] >= x - k:
						a = rows[y][ind][1]
						newlayer.append(a)
						comps[a] = num
						ind -= 1
					ind = rowind[j] + 1
					while ind < len(rows[y]) and comps[rows[y][ind][1]] == -1 and rows[y][ind][0] <= x + k:
						a = rows[y][ind][1]
						newlayer.append(a)
						comps[a] = num
						ind += 1
					ind = colind[j] - 1
					while ind >= 0 and comps[cols[x][ind][1]] == -1 and cols[x][ind][0] >= y - k:
						a = cols[x][ind][1]
						newlayer.append(a)
						comps[a] = num
						ind -= 1
					ind = colind[j] + 1
					while ind < len(cols[x]) and comps[cols[x][ind][1]] == -1 and cols[x][ind][0] <= y + k:
						a = cols[x][ind][1]
						newlayer.append(a)
						comps[a] = num
						ind += 1
				layer = newlayer
			num += 1
			short.append(sml)
	short.sort()
	l = len(short)
	need = l - 1
	for i in range(l):
		if short[i] < l - 1 - i:
			need -= 1
	print(need)