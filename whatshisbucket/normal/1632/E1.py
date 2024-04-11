import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

class BIT():
    def __init__(self, a, l, r):
        self.a = a
        self.l = l
        self.r = r
        self.mid = (l + r) // 2
        if r - l == 1:
            self.left = None
            self.right = None
            self.big = a[l]
        else:
            self.left = BIT(a, l, self.mid)
            self.right = BIT(a, self.mid, r)
            self.big = max(self.left.big, self.right.big)

    def partial(self, l, r):
        if r <= l:
            return -1000000
        if self.r == r and self.l == l:
            return self.big
        elif r <= self.mid:
            return self.left.partial(l, r)
        elif l >= self.mid:
            return self.right.partial(l, r)
        return max(self.left.partial(l, self.mid), self.right.partial(self.mid, r))

t, = I()
for _ in range(t):
    n, = I()
    graph = [[] for i in range(n)]
    for i in range(n - 1):
        a, b = I()
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)

    parents = [None] * n
    parents[0] = -1
    children = [[] for i in range(n)]
    layer = [0]
    while layer:
        newlayer = []
        for guy in layer:
            for boi in graph[guy]:
                if parents[boi] is None:
                    newlayer.append(boi)
                    children[guy].append(boi)
                    parents[boi] = guy
        layer = newlayer
    parents[0] = None
    inds = [0] * n
    order = []
    curr = 0
    while curr is not None:
        if inds[curr] == len(children[curr]):
            order.append(curr)
            curr = parents[curr]
        else:
            inds[curr] += 1
            curr = children[curr][inds[curr] - 1]

    depth = [-1] * n
    depth[0] = 0
    i = n - 2
    while i >= 0:
        depth[order[i]] = depth[parents[order[i]]] + 1
        i -= 1

    lowest = [0] * n
    for v in order:
        if children[v]:
            big = max(lowest[i] for i in children[v])
            lowest[v] = big + 1

    depth = lowest[0]
    path = [0]
    curr = 0
    while True:
        biggest = -1
        count = 0
        rep = None
        for child in children[curr]:
            if lowest[child] > biggest:
                biggest = lowest[child]
                count = 1
                rep = child
            elif lowest[child] == biggest:
                count += 1
        if count == 1:
            path.append(rep)
            curr = rep
        else:
            break

    other = [0] * len(path)
    for i in range(len(path) - 1):
        if len(children[path[i]]) == 1:
            other[i] = 0
        else:
            other[i] = max(lowest[j] for j in children[path[i]] if j != path[i + 1]) + 1
    other[-1] = lowest[path[-1]]
    bigs = [other[0]]
    for i in range(len(path) - 1):
        bigs.append(max(bigs[-1], other[i + 1] + i + 1))
    # print(path)
    # print(other)
    # print(bigs)
    # print(children)
    # print(parents)
    # print(lowest)

    xx = [other[i] - i for i in range(len(path))]
    bit = BIT(xx, 0, len(path))
    if len(path) == 1:
        out = [lowest[0]] * n
    else:
        out = []
        curr = 2
        for x in range(1, n + 1):
            if x >= len(path) - 1:
                out.append(lowest[0])
                continue
            currcost = max(bigs[(x + curr) // 2], lowest[path[curr]] + x, bit.partial((x + curr) // 2 + 1, curr) + x + curr)
            while curr < len(path) - 1:
                #print(x, curr)
                nextcost = max(bigs[(x + curr + 1) // 2], lowest[path[curr + 1]] + x, bit.partial((x + curr + 1) // 2 + 1, curr + 1) + x + curr + 1)
                if nextcost < currcost:
                    curr += 1
                    currcost = nextcost
                else:
                    break
            if curr >= len(path):
                out.append(lowest[0])
            else:
                out.append(currcost)
    print(*out)