import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, m, r, c = I()
	r -= 1
	c -= 1
	things = []
	for i in range(n):
		things.append(input())
	if things[r][c] == 'B':
		print(0)
		continue
	for i in range(n):
		if things[i][c] == 'B':
			print(1)
			break
	else:
		for i in range(m):
			if things[r][i] == 'B':
				print(1)
				break
		else:
			for i in range(n):
				if 'B' in things[i]:
					print(2)
					break
			else:
				print(-1)