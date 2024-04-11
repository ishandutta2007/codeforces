n = (int)(raw_input())
ed = [[] for x in range(0, n)]
vis = [0 for x in range(0, n)]
for i in range(1, n):
    x, y = map(int, raw_input().split())
    x -= 1
    y -= 1
    ed[x].append(y)
    ed[y].append(x)
ret = 0.0;
d = [0 for x in range(0, n)]
Q = [0]
d[0] = 1
vis[0] =1
pos = 0
while (pos < n):
    u = Q[pos]
    pos += 1
    ret += 1.0 / d[u]
    for v in ed[u]:
        if(vis[v] == 0):
            vis[v] = 1
            d[v] = d[u] + 1
            Q.append(v)
print ret