import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n, m = map(int, input().split())

rebase = lambda x : int(x) - 1

E = [[] for u in range(n)]
for j in range(m):
    u, v = map(rebase, input().split())
    E[u].append(v)
    E[v].append(u)

t = list(map(rebase, input().split()))

vis = [False] * n
for u in range(n):
    for v in E[u]:
        vis[t[v]] = True
    x = 0
    while vis[x]:
        x += 1
    if x != t[u]:
        print(-1)
        exit()
    for v in E[u]:
        vis[t[v]] = False

p = list(zip(t, range(n)))
p.sort()

print(*[u + 1 for x, u in p])