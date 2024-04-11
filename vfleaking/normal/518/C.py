n, m, k = map(int, raw_input().split())

a = map(int, raw_input().split())
b = map(int, raw_input().split())

apos = [0 for i in xrange(n + 1)]
for i, v in enumerate(a):
    apos[v] = i

res = 0
for x in b:
    res += apos[x] / k + 1
    if apos[x] > 0:
        y = a[apos[x] - 1]
        a[apos[x] - 1], a[apos[x]] = x, y
        apos[x], apos[y] = apos[y], apos[x]

print res