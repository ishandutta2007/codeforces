import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

E = [[] for u in range(n)]

for j in range(m):
    u, v = map(lambda x: int(x) - 1, input().split())
    E[u].append(v)
    E[v].append(u)

vis = [False] * n
tour = []

stk = [0]
while stk:
    u = stk[-1]
    tour.append(u)
    vis[u] = True
    while E[u] and vis[E[u][-1]]:
        E[u].pop()
    if E[u]:
        v = E[u].pop()
        stk.append(v)
    else:
        stk.pop()

L = len(tour)
r = L % k

i = 0
for j in range(k):
    c = []
    for t in range(L // k + (1 if j < r else 0)):
        c.append(tour[i] + 1)
        i += 1
    assert(len(c) <= (2 * n + k - 1) // k)
    print(len(c), *c)