import sys

def r():
    return list(map(int, input().split()))

n = int(input())
edge = [r() for i in range(n-1)]

adj = [[] for i in range(n+1)]
for e in edge:
    adj[e[0]].append(e[1])
    adj[e[1]].append(e[0])

prob = [0.0 for i in range(n+1)]
d = [0 for i in range(n+1)]
visited = [False for i in range(n+1)]

prob[1] = 1
ans = 0.0

st = [1]
visited[1] = True
while st:
    u = st.pop()
    cnt = len(adj[u])
    if u != 1:
        cnt -= 1
    if cnt == 0:
        ans = ans + prob[u]*d[u]
    else:
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                prob[v] = prob[u]*(1.0/cnt)
                d[v] = d[u]+1
                st.append(v)
                
print(ans)