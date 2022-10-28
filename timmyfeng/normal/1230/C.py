n, m = map(int, raw_input().split())

edge = []
for x in xrange(m):
    edge.append(map(int, raw_input().split()))

val = [0] * (n + 1)

def dfs(x):
    res = 0
    if x == n:
        s = set()
        for a, b in edge:
            c, d = val[a], val[b]
            if c > d:
                c, d = d, c
            if (c, d) not in s:
                s.add((c, d))
                res += 1
    else:
        for i in xrange(6):
            val[x + 1] = i
            res = max(res, dfs(x + 1))
    return res

print(dfs(0))