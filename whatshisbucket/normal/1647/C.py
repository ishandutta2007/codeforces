import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, m = I()
	table = []
	for i in range(n):
		table.append([*map(int, [*input()])])
	if table[0][0] == 1:
		print(-1)
		continue
	moves = []
	for i in range(n - 1, -1, -1):
		for j in range(m - 1, -1, -1):
			if table[i][j] == 0:
				moves.append((i, j, i, j))
			else:
				if i > 0:
					moves.append((i - 1, j, i, j))
				else:
					moves.append((i, j - 1, i, j))
	print(len(moves))
	for i in range(len(moves)):
		moves[i] = ' '.join(str(guy + 1) for guy in moves[i])
	print('\n'.join(moves))