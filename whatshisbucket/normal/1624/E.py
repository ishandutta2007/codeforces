import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	I()
	n, m = I()
	triples = {i: None for i in range(1000)}
	pairs = {i: None for i in range(100)}
	for i in range(n):
		phone = [*map(int, [*sys.stdin.readline().strip()])]
		for j in range(m - 1):
			pairs[10 * phone[j] + phone[j + 1]] = (i, j)
		for j in range(m - 2):
			triples[100 * phone[j] + 10 * phone[j + 1] + phone[j + 2]] = (i, j)
	phone = [*map(int, [*sys.stdin.readline().strip()])]
	if m == 1:
		print(-1)
		continue
	if m == 2:
		x = 10 * phone[0] + phone[1]
		if pairs[x] is not None:
			print(1)
			b, c = pairs[x]
			print(c + 1, c + 2, b + 1)
		else:
			print(-1)
		continue
	last = [None] * m
	x = 10 * phone[0] + phone[1]
	y = 100 * phone[0] + 10 * phone[1] + phone[2]
	if pairs[x] is not None:
		last[1] = (2, pairs[x][0], pairs[x][1])
	if triples[y] is not None:
		last[2] = (3, triples[y][0], triples[y][1])
	for i in range(3, m):
		x = 10 * phone[i - 1] + phone[i]
		y = 100 * phone[i - 2] + 10 * phone[i - 1] + phone[i]
		if pairs[x] is not None and last[i - 2] is not None:
			last[i] = (2, pairs[x][0], pairs[x][1])
		elif triples[y] is not None and last[i - 3] is not None:
			last[i] = (3, triples[y][0], triples[y][1])
	if last[-1] is not None:
		l = []
		i = m - 1
		while i > 0:
			a, b, c = last[i]
			l.append((c + 1, c + a, b + 1))
			i -= a
		print(len(l))
		for guy in l[::-1]:
			print(*guy)
	else:
		print(-1)