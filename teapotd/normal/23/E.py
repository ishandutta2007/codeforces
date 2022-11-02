from fractions import Fraction

n = int(input())
G = [[] for i in range(n)]

for i in range(n-1):
    a, b = (int(x)-1 for x in input().split())
    G[a].append(b)
    G[b].append(a)

f, g, h = [1]*n, [1]*n, [1]*n

def dfs(v, p):
    if p != -1:
        G[v].remove(p)

    for e in G[v]:
        dfs(e, v)
        h[v] *= f[e]

    tmp = []
    f[v], g[v] = h[v], h[v]*2

    for e in G[v]:
        f[v] = max(f[v], h[v] // f[e] * g[e])
        tmp.append((f[e], h[e]))

    fPart, hPart = h[v], 1
    tmp.sort(key=lambda x: Fraction(*x))

    for i in range(len(tmp)):
        fPart //= tmp[i][0]
        hPart *= tmp[i][1]
        f[v] = max(f[v], fPart*hPart*(i+2))
        g[v] = max(g[v], fPart*hPart*(i+3))

dfs(0, -1)
print(f[0])