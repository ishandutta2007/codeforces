class DSU(object):
    def __init__(self, n):
        self.p = list(range(n))
        self.rk = [0] * n

    def find(self, u):
        while u != self.p[u]:
            u = self.p[u]
        return u

    def unite(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u == v:
            return

        if self.rk[u] < self.rk[v]:
            u, v = v, u
        self.p[v] = u
        self.rk[u] += self.rk[u] == self.rk[v]

n = int(input())
p = list(map(int, input().split()))

dsu = DSU(n)
s = None

for u in range(n):
    p[u] -= 1
    if p[u] == u:
         s = u
for u in range(n):
    dsu.unite(u, p[u])

ans = 0
rt = [None] * n

vis = [False] * n
for u in range(n):
    if dsu.find(u) != u:
        continue

    v = u
    while not vis[v]:
        vis[v] = True
        v = p[v]

    rt[u] = v
    if p[v] != v:
        p[v] = v
        if s is None:
            ans += 1
            s = v

for u in range(n):
    if u != dsu.find(s) and u == dsu.find(u):
        p[rt[u]] = s
        ans += 1

print(ans)
for u in range(n):
    p[u] += 1
print(*p)