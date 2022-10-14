from collections import deque
from itertools import accumulate
from sys import stdin
 
for _ in range(int(stdin.readline())):
    n, m, a, b, c = [int(x) for x in stdin.readline().split()]
    p = list(accumulate([0, *sorted(int(x) for x in stdin.readline().split())]))
    adj = [[] for i in range(n + 1)]
    for e in range(m):
        u, v = [int(x) for x in stdin.readline().split()]
        adj[u].append(v)
        adj[v].append(u)
 
    da, db, dc = [-1 for i in range(n + 1)], [-1 for i in range(n + 1)], [-1 for i in range(n + 1)]
    for s, d in ((a, da), (b, db), (c, dc)):
        q = deque([s])
        d[s] = 0
        while len(q) > 0:
            u = q.popleft()
            for v in adj[u]:
                if d[v] == -1:
                    d[v] = d[u] + 1
                    q.append(v)
 
    print(min(p[db[x]] + p[db[x] + da[x] + dc[x]] for x in range(1, n + 1) if db[x] + da[x] + dc[x] < n))