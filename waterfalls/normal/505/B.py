def dfs(x,c):
    vis[x] = 1
    for i in adj[c][x]:
        if not vis[i]:
            dfs(i,c)

def check(u,v,c):
    for i in range(1,n+1):
        vis[i] = False
    dfs(u,c)
    return vis[v]

n,m = map(int,input().split())

adj = []
for i in range(m+1):
    adj.append([])
    for j in range(n+1):
        adj[i].append([])
vis = [False]*(n+1)

for i in range(m):
    a,b,c = map(int,input().split())
    adj[c][a].append(b)
    adj[c][b].append(a)

q = int(input())
for i in range(q):
    u,v = map(int,input().split())
    ans = 0;
    for c in range(1,m+1):
        if check(u,v,c):
            ans+=1
    print(ans)