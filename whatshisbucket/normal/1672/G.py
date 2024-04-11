# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

M = 998244353
r, c = I()
rows = []
for i in range(r):
	rows.append([*input()])
if r % 2 == 0 and c % 2 == 0:
	blanks = 0
	for i in range(r):
		blanks += rows[i].count('?')
	print(pow(2, blanks, M))
elif r % 2 + c % 2 == 1:
	if r % 2 == 1:
		nrows = []
		for i in range(c):
			nrows.append([rows[j][i] for j in range(r)])
		rows = nrows
	ones = 1
	zeroes = 1
	for row in rows:
		unk = 0
		xor = 0
		for char in row:
			if char == '?':
				unk += 1
			elif char == '1':
				xor = 1 - xor
		if unk == 0:
			if xor == 1:
				zeroes = 0
			else:
				ones = 0
		else:
			zeroes = zeroes * pow(2, unk - 1, M) % M
			ones = ones * pow(2, unk - 1, M ) % M
	print((ones + zeroes) % M)
else:
	RC = [0] * (r + c)
	edges = [[] for i in range(r + c)]
	for i in range(r):
		for j in range(c):
			char = rows[i][j]
			if char == '?':
				edges[i].append(j + r)
				edges[j + r].append(i)
			elif char == '1':
				RC[i] = 1 - RC[i]
				RC[r + j] = 1 - RC[r + j]
	seen = [0] * (r + c)
	zeroes = []
	ones = []
	for i in range(r + c):
		if not seen[i]:
			component = [i]
			seen[i] = 1
			j = 0
			while j < len(component):
				if len(component) == r + c:
					break
				for v in edges[component[j]]:
					if not seen[v]:
						seen[v] = 1
						component.append(v)
				j += 1
			n = len(component)
			m = 0
			x = 0
			for v in component:
				m += len(edges[v])
				x ^= RC[v]
			m //= 2
			if n % 2 == 0:
				if x == 0:
					y = pow(2, m - n + 1, M)
					zeroes.append(y)
					ones.append(y)
				else:
					print(0)
					exit()
			else:
				y = pow(2, m - n + 1, M)
				if x == 0:
					zeroes.append(y)
					ones.append(0)
				else:
					ones.append(y)
					zeroes.append(0)
	zs = 1
	for g in zeroes:
		zs = zs * g % M
	os = 1
	for g in ones:
		os = os * g % M
	print((zs + os) % M)