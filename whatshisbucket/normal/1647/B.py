import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, m = I()
	table = []
	for i in range(n):
		table.append([*map(int, [*input()])])
	bad = False
	for i in range(n - 1):
		for j in range(m - 1):
			l = [table[i][j], table[i + 1][j], table[i][j + 1], table[i + 1][j + 1]]
			if l.count(0) == 1:
				bad = True
	if bad:
		print('NO')
	else:
		print('YES')