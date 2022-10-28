import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	I()
	m, n = I()
	p = [I() for i in range(m)]
	q = [[p[i][j] for i in range(m)] for j in range(n)]
	big = [max(q[i]) for i in range(n)]
	if m < n:
		print(min(big))
		continue
	inds = [set(range(m)) for i in range(n)]
	ones = 0
	order = []
	for i in range(m):
		for j in range(n):
			order.append((p[i][j], i, j))
	order.sort()
	uses = [n] * m
	ind = 0
	done = False
	for i in range(m * n):
		val, store, person = order[i]
		inds[person].remove(store)
		uses[store] -= 1
		while ind < m and uses[ind] <= 1:
			ind += 1
		if ind == m:
			print(val)
			done = True
			break
		if len(inds[person]) == 0:
			print(val)
			done = True
			break
	if not done:
		print(min(big))