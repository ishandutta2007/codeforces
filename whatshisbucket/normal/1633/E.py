import sys
I = lambda: [*map(int, sys.stdin.readline().split())]
import heapq
import time

def prim(graph, adjust):
    included = [0] * n
    used = [0] * m
    #print(adjust)
    included[0] = 1
    tot = 1
    cost = 0
    edges = []
    for w, v, i in graph[0]:
        heapq.heappush(edges, (abs(w - adjust), v, i))
    while tot < n:
        w, v, i = heapq.heappop(edges)
        if included[v] == 0:
            #print(w, v)
            used[i] = 1
            cost += w
            tot += 1
            included[v] = 1
            for w, u, i in graph[v]:
                if included[u] == 0:
                    heapq.heappush(edges, (abs(w - adjust), u, i))
    return [cost, used]


n, m = I()
graph = [[] for i in range(n)]
weight = []
for i in range(m):
    u, v, w = I()
    weight.append(w)
    graph[u - 1].append((w, v - 1, i))
    graph[v - 1].append((w, u - 1, i))

tester = n == 50 and 24986559 in weight
p, k, a, b, c = I()
q = I()
# if tester:
#     print(k)
#     print(time.time())

known = {}
changes = []
for i in range(m):
    for j in range(m):
        mid = (weight[i] + weight[j]) // 2
        changes.append(mid)
        changes.append(mid + 1)
        if (weight[i] - weight[j] % 2) == 0:
            changes.append(mid - 1)

changes = sorted(list(set(changes)))
known[changes[0]] = prim(graph, changes[0])
known[changes[-1]] = prim(graph, changes[-1])
last = known[changes[-1]][1]
l = len(changes)
curr = 0
firsts = [0]
while known[changes[curr]][1] != known[changes[-1]][1]:
    x = known[changes[curr]][1]
    sml = curr + 1
    big = l
    while big - sml > 1:
        mid = (big + sml) // 2
        if changes[mid] in known:
            y = known[changes[mid]][1]
        else:
            yy = prim(graph, changes[mid])
            known[changes[mid]] = yy
            y = yy[1]
        if y == x:
            sml = mid
        else:
            big = mid
    firsts.append(sml + 1)
    if changes[sml + 1] not in known:
        known[changes[sml + 1]] = prim(graph, changes[sml + 1])
    curr = sml + 1

use = []
for guy in firsts:
    use.append(changes[guy])
    if guy > 0:
        use.append(changes[guy - 1])
for i in range(m):
    use.append(weight[i])
use = sorted(list(set(use)))

refs = []
for guy in use:
    if guy in known:
        refs.append((guy, known[guy][0]))
    else:
        refs.append((guy, prim(graph, guy)[0]))

# if tester:
#     print(time.time())
#print(refs)
j = p
out = 0
while j < k:
    q.append((a * q[-1] + b) % c)
    j += 1
q.sort()
# if tester:
#     print(time.time())
ind = -1
for guy in q:
    while ind < len(refs) - 1 and refs[ind + 1][0] <= guy:
        ind += 1
    if ind == -1:
        res = refs[0][1] + (n - 1) * (refs[0][0] - guy)
    elif ind == len(refs) - 1:
        res = refs[-1][1] + (n - 1) * (guy - refs[-1][0])
    else:
        res = refs[ind][1] + (guy - refs[ind][0]) * (refs[ind + 1][1] - refs[ind][1]) // (refs[ind + 1][0] - refs[ind][0])
    out ^= res
# if tester:
#     print(time.time())
print(out)