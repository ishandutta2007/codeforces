import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, m, rb, cb, rd, cd = I()
	if rb <= rd:
		rowtime = rd - rb
	else:
		rowtime = 2 * n - rd - rb
	if cb <= cd:
		coltime = cd - cb
	else:
		coltime = 2 * m - cd - cb
	print(min(rowtime, coltime))