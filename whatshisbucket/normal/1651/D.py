import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, = I()
points = []
for i in range(n):
	x, y = I()
	points.append((x, y))

botleft = {}
topleft = {}
botright = {}
topright = {}
pset = set(points)
point = points[:]
point.sort(key = lambda x: x[0] + x[1])
for x, y in point:
	if (x, y - 1) not in pset:
		botleft[(x, y)] = [1, (x, y - 1)]
	elif (x - 1, y) not in pset:
		botleft[(x, y)] = [1, (x - 1, y)]
	else:
		a = botleft[(x, y - 1)]
		b = botleft[(x - 1, y)]
		if a[0] < b[0]:
			add = a[:]
		else:
			add = b[:]
		add[0] += 1
		botleft[(x, y)] = add
point.sort(key = lambda x: x[0] - x[1])
for x, y in point:
	if (x, y + 1) not in pset:
		topleft[(x, y)] = [1, (x, y + 1)]
	elif (x - 1, y) not in pset:
		topleft[(x, y)] = [1, (x - 1, y)]
	else:
		a = topleft[(x, y + 1)]
		b = topleft[(x - 1, y)]
		if a[0] < b[0]:
			add = a[:]
		else:
			add = b[:]
		add[0] += 1
		topleft[(x, y)] = add
point.sort(key = lambda x: x[1] - x[0])
for x, y in point:
	if (x, y - 1) not in pset:
		botright[(x, y)] = [1, (x, y - 1)]
	elif (x + 1, y) not in pset:
		botright[(x, y)] = [1, (x + 1, y)]
	else:
		a = botright[(x, y - 1)]
		b = botright[(x + 1, y)]
		if a[0] < b[0]:
			add = a[:]
		else:
			add = b[:]
		add[0] += 1
		botright[(x, y)] = add
point.sort(key = lambda x: -x[1] - x[0])
for x, y in point:
	if (x, y + 1) not in pset:
		topright[(x, y)] = [1, (x, y + 1)]
	elif (x + 1, y) not in pset:
		topright[(x, y)] = [1, (x + 1, y)]
	else:
		a = topright[(x, y + 1)]
		b = topright[(x + 1, y)]
		if a[0] < b[0]:
			add = a[:]
		else:
			add = b[:]
		add[0] += 1
		topright[(x, y)] = add

prin = sys.stdout.write
for guy in points:
	best = float('inf')
	point = None
	if botleft[guy][0] < best:
		best = botleft[guy][0]
		point = botleft[guy][1]
	if botright[guy][0] < best:
		best = botright[guy][0]
		point = botright[guy][1]
	if topleft[guy][0] < best:
		best = topleft[guy][0]
		point = topleft[guy][1]
	if topright[guy][0] < best:
		best = topright[guy][0]
		point = topright[guy][1]
	prin(str(point[0]) + ' ' + str(point[1]) + '\n')