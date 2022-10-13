n = int(raw_input())
v = [int(x) for x in raw_input().split()]
edges = []
for _ in xrange(n):
	edges.append([])
for i in xrange(n-1):
	par, val = (int(x) for x in raw_input().split())
	par -= 1
	edges[par].append((i+1, val))

dp = [0] * n
q = [0]
ret = 0
while q:
	curr = q.pop()
	if dp[curr] > v[curr]:
		ret += 1
		dp[curr] = 1000000000000000000
	for edge in edges[curr]:
		dest = edge[0]
		contrib = edge[1]
		dp[dest] = max(dp[dest], dp[curr] + contrib)
		q.append(dest)

print ret