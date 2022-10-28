import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

n, m = I()
mat = []
for i in range(n):
	mat.append(I())

queued = [[0] * m for i in range(n)]

q = []
for i in range(n - 1):
	for j in range(m - 1):
		if mat[i][j] == mat[i][j + 1] == mat[i + 1][j] == mat[i + 1][j + 1]:
			q.append((i, j, mat[i][j]))
			queued[i][j] = 1

qind = 0
out = []
while qind < len(q):
	i, j, c = q[qind]
	out.append(q[qind])
	mat[i][j] = 0
	mat[i + 1][j] = 0
	mat[i][j + 1] = 0
	mat[i + 1][j + 1] = 0
	for di in range(i - 1, i + 2):
		for dj in range(j - 1, j + 2):
			if di != i or dj != j:
				if di >= 0 and di < n - 1 and dj >= 0 and dj < m - 1 and not queued[di][dj]:
					x = set([mat[di][dj], mat[di][dj + 1], mat[di + 1][dj], mat[di + 1][dj + 1]])
					if len(x) == 2 and 0 in x:
						c = 0
						for guy in x:
							if guy != 0:
								c = guy
						q.append((di, dj, c))
						queued[di][dj] = 1
	qind += 1

bad = False
for i in range(n):
	for j in range(m):
		if mat[i][j] != 0:
			bad = True
if bad:
	print(-1)
else:
	print(len(out))
	for i, j, c in out[::-1]:
		sys.stdout.write(str(i + 1) + ' ' + str(j + 1) + ' ' + str(c) + '\n')