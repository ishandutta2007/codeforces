visited = []
def dfs(adj,s):
	visited[s] = True
	for i in adj[s]:
		if not visited[i]:
			dfs(adj,i)
n = int(input())
a = list(map(int,input().split()))
adj = []
for i in range(n+5):
	adj.append([])
	visited.append(False)
for i in range(n):
	adj[i+1].append(a[i])
	adj[a[i]].append(i+1)
ans = 0	
for i in range(1,n+1):
	if not visited[i]:
		ans += 1
		dfs(adj,i)
print(ans)