n, k = map(int, input().split())

x = (n - 1) // k
r = (n - 1) % k

edges = []
u = 1
for j in range(k):
    prv = 0
    for i in range(x + 1 if j < r else x):
        edges.append((u, prv))
        prv = u
        u += 1

cost = 2 * x + (2 if r >= 2 else 1 if r >= 1 else 0)
print(cost)
for u, v in edges:
    print(u + 1, v + 1)