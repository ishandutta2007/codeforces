import sys
input = sys.stdin.readline
import math

for _ in range(1):
    n, m = map(int, input().split())
    g = [[] for i in range(n)]
    deg = [0] * n
    in_deg = [0] * n
    out_deg = [0] * n
    for i in range(m):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        g[x].append(y)
        deg[y] += 1
        out_deg[x] += 1
        in_deg[y] += 1
    order = []
    for i in range(n):
        if deg[i] == 0:
            order.append(i)
    for i in range(n):
        for to in g[order[i]]:
            deg[to] -= 1
            if deg[to] == 0:
                order.append(to)
    dp = [1] * n
    for i in order:
        for j in g[i]:
            if in_deg[j] > 1 and out_deg[i] > 1:
                dp[j] = max(dp[j], dp[i] + 1)
    print(max(dp))