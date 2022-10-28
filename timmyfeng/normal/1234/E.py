import sys
range = xrange
input = raw_input

n, m = [ int(x) for x in input().split() ]
a = [ int(x) for x in input().split() ]

tot = 0
ps = [0] * (n + 1)
con = [0] * (n + 1)
req = [ [] for _ in range(n + 1) ]
for i in range(1, m):
    if a[i] == a[i - 1]:
        continue
    u, v = sorted([a[i], a[i - 1]])
    ps[u + 1] += 1
    ps[v] -= 1
    con[u] += v - u
    con[v] += v - u
    req[u].append(v)
    req[v].append(u)
    tot += v - u

for i in range(1, n + 1):
    ps[i] += ps[i - 1]

out = []
for i in range(1, n + 1):
    res = tot - ps[i] - con[i]
    for j in req[i]:
        res += j if j < i else j - 1
    out.append(res)

print ' '.join(str(x) for x in out)