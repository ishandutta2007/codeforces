import sys
I = lambda: [*map(int, input().split())]

t, = I()
for _ in range(t):
	n, = I()
	diffs = [0] * n
	for i in range(3, n + 1):
		print('?', 1, 2, i)
		diffs[i - 1], = I()

	x = max(diffs)
	if diffs.count(x) == n - 2:
		diffs1 = [0] * n
		for i in range(1, n + 1):
			if i != 3 and i != 4:
				print('?', 3, 4, i)
				diffs1[i - 1], = I()
		y = max(diffs1)
		if y <= x:
			print('!', 1, 2)
		else:
			if diffs1.count(y) == n - 2:
				print('!', 3, 4)
			else:
				print('!', 3, diffs1.index(y) + 1)

	else:
		ind = diffs.index(x)
		diffs1 = [0] * n
		for i in range(2, n + 1):
			if i != ind + 1:
				print('?', 1, ind + 1, i)
				diffs1[i - 1], = I()
		y = max(diffs1)
		if diffs1.count(y) > 1:
			print('!', 1, ind + 1)
		else:
			ind1 = diffs1.index(y)
			print('!', ind + 1, ind1 + 1)