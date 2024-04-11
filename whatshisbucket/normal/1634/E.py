import io,os
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda: [*map(int, read.readline().split())]

class Edge():
	def __init__(self, arr, val, i):
		self.arr = arr
		self.val = val
		self.i = i
		self.used = False

m, = I()
nums = {}
arrs = [[] for i in range(m)]

for i in range(m):
	n, = I()
	a = I()
	if len(a) % 2 == 1:
		exit()
	for j in range(n):
		edge = Edge(i, a[j], j)
		arrs[i].append(edge)
		if a[j] in nums:
			nums[a[j]].append(edge)
		else:
			nums[a[j]] = [edge]

arrinds = [0] * m
numinds = {i: 0 for i in nums}

for guy in nums:
	if len(nums[guy]) % 2 == 1:
		print('NO')
		exit()

paths = []
for i in range(m):
	while arrinds[i] < len(arrs[i]):
		while arrinds[i] < len(arrs[i]) and arrs[i][arrinds[i]].used:
			arrinds[i] += 1
		if arrinds[i] < len(arrs[i]):
			path = []
			curr = i
			while len(path) == 0 or curr != i:
				while arrs[curr][arrinds[curr]].used:
					arrinds[curr] += 1
				e = arrs[curr][arrinds[curr]]
				path.append(e)
				e.used = True
				curr1 = e.val
				while nums[curr1][numinds[curr1]].used:
					numinds[curr1] += 1
				e1 = nums[curr1][numinds[curr1]]
				path.append(e1)
				e1.used = True
				curr = e1.arr
			paths.append(path)

colors = [[0] * len(arrs[i]) for i in range(m)]
for path in paths:
	for i in range(len(path)):
		e = path[i]
		if i % 2 == 0:
			colors[e.arr][e.i] = 'L'
		else:
			colors[e.arr][e.i] = 'R'

print('YES')
print('\n'.join(''.join(colors[i]) for i in range(m)))