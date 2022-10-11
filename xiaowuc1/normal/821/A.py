n = int(raw_input())
g = []
for _ in xrange(n):
    g.append([int(x) for x in raw_input().split()])

ret = "Yes"
for i in xrange(n):
    for j in xrange(n):
        if g[i][j] == 1:
            continue
        found = False
        for k in xrange(n):
            for l in xrange(n):
                if g[i][j] == g[i][k] + g[l][j]:
                    found = True
        if not found:
            ret = "No"
print ret