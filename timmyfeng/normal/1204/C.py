n = input()
dist = [[10 ** 9 if c == '0' else 1 for c in raw_input()] for i in xrange(n)]

for i in xrange(n):
    dist[i][i] = 0

for k in xrange(n):
    for i in xrange(n):
        for j in xrange(n):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

m = input()
p = [int(i) - 1 for i in raw_input().split()]

v = [0]
for i in xrange(2, m):
    if dist[p[v[-1]]][p[i]] < i - v[-1]:
        v.append(i - 1)
v.append(m - 1)

print len(v)
print ' '.join([str(p[i] + 1) for i in v])