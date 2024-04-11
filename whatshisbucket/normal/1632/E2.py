# import sys
# I = lambda: [*map(int, sys.stdin.readline().split())]

import io,os
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda:map(int, read.readline().split())
 
def maxsparse(a):
	l = []
	l.append(a)
	c = 1
	while c < len(a):
		new = []
		for i in range(len(a)):
			if i + c < len(l[-1]):
				new.append(max(l[-1][i], l[-1][i + c]))
			else:
				break
		l.append(new)
		c *= 2
	return l
 
def partial(table, i, j):
	if j <= i:
		return -1000000
	yyy = 1
	aaa = 0
	while 2 * yyy <= j - i:
		yyy *= 2
		aaa += 1
	return max(table[aaa][i], table[aaa][j - yyy])
 
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
    sparse = maxsparse(xx)
 
    if len(path) == 1:
        out = [lowest[0]] * n
    else:
        out = []
        curr = 2
        currcost = -1
        for x in range(1, n + 1):
            if x >= len(path) - 1 or currcost >= lowest[0]:
                out.append(lowest[0])
                continue
            currcost = max(bigs[(x + curr) // 2], lowest[path[curr]] + x, partial(sparse, (x + curr) // 2 + 1, curr) + x + curr)
            while curr < len(path) - 1:
                #print(x, curr)
                nextcost = max(bigs[(x + curr + 1) // 2], lowest[path[curr + 1]] + x, partial(sparse, (x + curr + 1) // 2 + 1, curr + 1) + x + curr + 1)
                if nextcost < currcost:
                    curr += 1
                    currcost = nextcost
                else:
                    break
            out.append(currcost)
    print(*out)