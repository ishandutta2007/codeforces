#http://codeforces.com/contest/601/problem/A
import sys
from collections import deque

n, m = map(int, input().split())
g = set()
for i in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    g |= {(x, y), (y, x)}

cut = (0, n-1) in g

q = deque()
q.append(0)

d = [-1] * n
d[0] = 0
while len(q):
    x = q.popleft()
    for y in range(n):
        if cut ^ ((x, y) in g) and (d[y] == -1 or d[y] > d[x] + 1):
            d[y] = d[x] + 1
            q.append(y)

print(d[n-1])