n, m = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(n)]

a = [0] * n
b = [0] * m
a[0] = min(g[0])

for j in range(m):
    g[0][j] -= a[0]
    b[j] = g[0][j]

good = True

for i in range(n):
    for j in range(m):
        g[i][j] -= b[j]

    if min(g[i]) < 0 or min(g[i]) != max(g[i]):
        good = False
    a[i] += min(g[i])

if not good:
    print(-1)
else:
    if n > m:
        x = min(a)
        for i in range(n):
            a[i] -= x
        for j in range(m):
            b[j] += x

    num = sum(a) + sum(b)
    print(num)
    for i in range(n):
        for _ in range(a[i]):
            print('row {}'.format(i + 1))
    for j in range(m):
        for _ in range(b[j]):
            print('col {}'.format(j + 1))