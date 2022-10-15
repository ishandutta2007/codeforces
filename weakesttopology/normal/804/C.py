from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

src = 0

X = []
for u in range(n):
    X.append(list(map(lambda x: int(x) - 1, input().split())))
    X[u] = X[u][1:]
    if len(X[u]) > len(X[src]):
        src = u

E = [[] for u in range(n)]
for j in range(n - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
    E[u].append(v)
    E[v].append(u)

color = [0] * m
vis = [False] * n
used = [False] * (m + 1)

q = deque()
q.append(src)

while q:
    u = q.popleft()
    vis[u] = True
    for x in X[u]:
        used[color[x]] = True
    ptr = 1
    for x in X[u]:
        if not color[x]:
            while used[ptr]:
                ptr += 1
            color[x] = ptr
            ptr += 1
    for x in X[u]:
        used[color[x]] = False

    for v in E[u]:
        if not vis[v]:
            q.append(v)

for x in range(m):
    if not color[x]:
        color[x] = 1

print(max(color))
print(*color)