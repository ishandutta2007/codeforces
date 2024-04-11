import heapq
inf = 1000000007

n, m, k = map(int, input().split())
E = [[] for _ in range(n)]
edges = []
for _ in range(m):
	u, v, w = map(int, input().split())
	E[u-1].append((v-1, w))
	E[v-1].append((u-1, w))
	edges.append((u-1, v-1, w))
routes = []
for _ in range(k):
	a, b = map(int, input().split())
	routes.append((a-1, b-1))

def dijkstra(st):
	pq, dist = [(0, st)], [inf if i!=st else 0 for i in range(n)]
	while len(pq)>0:
		d, u = heapq.heappop(pq)
		if d!=dist[u]:
			continue
		for v, w in E[u]:
			if dist[v]>dist[u]+w:
				dist[v] = dist[u]+w
				heapq.heappush(pq, (dist[v], v))
	return dist

dist = []
for i in range(n):
	dist.append(dijkstra(i))

ans = inf
for u, v, _ in edges:
	now = 0
	for a, b in routes:
		now += min(dist[a][b], dist[a][u]+dist[b][v], dist[a][v]+dist[b][u])
	ans = min(ans, now)

print(ans)