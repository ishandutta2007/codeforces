import sys
import heapq

nnode,nedge,source,dest=map(int,sys.stdin.readline().split())
source-=1;dest-=1
adjl=[[] for _ in range(nnode)]

for _ in range(nedge):
	u,v=map(int,sys.stdin.readline().split())
	u-=1;v-=1
	adjl[u].append(v)
	adjl[v].append(u)

# why not BFS? >.<
def dijkstra_from(source):
	pq=[]
	dist=[10**9]*nnode

	dist[source]=0
	heapq.heappush(pq,(dist[source],source))
	while pq:
		dist_node,node=heapq.heappop(pq)
		if dist[node]!=dist_node: continue

		for adj in adjl[node]:
			if dist[adj]>dist_node+1:
				dist[adj]=dist_node+1
				heapq.heappush(pq,(dist[adj],adj))

	return dist

d_src=dijkstra_from(source)
d_dst=dijkstra_from(dest)

assert d_dst[source] == d_src[dest]

ans=0
for u in range(nnode):
	adj_to_u=[False]*u
	for v in adjl[u]:
		if v<u:
			adj_to_u[v]=True
	for v in range(u):
		if not adj_to_u[v]:
			if min(
			d_dst[u]+d_src[v]+1,
			d_src[u]+d_dst[v]+1
			)<d_src[dest]: continue
			ans+=1

print(ans)