n = int(input())

E = [[] for u in range(n)]
for i in range(n - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
    E[u].append(v)
    E[v].append(u)

k = max([len(E[u]) for u in range(n)]) + 1

used = [False] * k
color = [0] * n

def getnext(x):
    while used[x]:
        x += 1
    return x

vis = [False] * n
stk = [0]

while stk:
    u = stk.pop()
    vis[u] = True
    used[color[u]] = True
    for v in E[u]:
        if vis[v]:
            used[color[v]] = True
    x = 0
    for v in E[u]:
        if not vis[v]:
            x = getnext(x)
            color[v] = x
            used[x] = True
            stk.append(v)

    used[color[u]] = False
    for v in E[u]:
        used[color[v]] = False

print(k)
print(*[x + 1 for x in color])