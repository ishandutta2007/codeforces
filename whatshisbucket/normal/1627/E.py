import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, m, k = I()
	x = I()
	leave = [[] for i in range(n)]
	enter = [[] for i in range(n)]
	enter[0] = [(0, 0)]
	for i in range(k):
		a, b, c, d, h = I()
		leave[a - 1].append((a - 1, b - 1, c - 1, d - 1, h))

	for i in range(n):
		if len(enter[i]) == 0:
			continue
		l = enter[i]
		l.sort()
		usable = []
		for guy in l:
			if len(usable) == 0:
				usable.append(guy)
			else:
				if guy[1] < usable[-1][1] + x[i] * (guy[0] - usable[-1][0]):
					while len(usable) > 0 and usable[-1][1] > guy[1] + x[i] * (guy[0] - usable[-1][0]):
						usable.pop()
					usable.append(guy)
		if len(leave[i]) == 0:
			continue
		leave[i].sort()
		ind = -1
		for a, b, c, d, h in leave[i]:
			while ind + 1 < len(usable) and usable[ind + 1][0] <= b:
				ind += 1
			if ind >= 0:
				left = usable[ind][1] + x[i] * (b - usable[ind][0])
			else:
				left = float('inf')
			if ind + 1 < len(usable):
				right = usable[ind + 1][1] + x[i] * (usable[ind + 1][0] - b)
			else:
				right = float('inf')
			enter[c].append((d, min(left, right) - h))

	if len(enter[-1]) == 0:
		print('NO ESCAPE')
	else:
		print(x[-1] * (m - 1 - usable[-1][0]) + usable[-1][1])