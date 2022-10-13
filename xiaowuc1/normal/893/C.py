n, m = (int(x) for x in raw_input().split())
v = [int(x) for x in raw_input().split()]

par = range(n)

seen = [False] * n

edges = []
for _ in xrange(n):
	edges.append([])

ret = 0
for i in xrange(m):
	a, b = (int(x) for x in raw_input().split())
	a -= 1
	b -= 1
	edges[a].append(b)
	edges[b].append(a)

from Queue import Queue

for i in xrange(len(seen)):
	if seen[i]:
		continue
	q = Queue()
	q.put(i)
	inc = v[i]
	while not q.empty():
		curr = q.get()
		for out in edges[curr]:
			if not seen[out]:
				seen[out] = True
				q.put(out)
		inc = min(inc, v[curr])
	ret += inc
print ret