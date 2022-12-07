import sys
input = sys.stdin.buffer.readline


class UnionFind():
    def __init__(self, n):
        self.n = n
        self.root = [-1] * (n + 1)
        self.rnk = [0] * (n + 1)

    def find_root(self, x):
        if self.root[x] < 0:
            return x
        else:
            self.root[x] = self.find_root(self.root[x])
            return self.root[x]

    def unite(self, x, y):
        x = self.find_root(x)
        y = self.find_root(y)
        if x == y:
            return
        elif self.rnk[x] > self.rnk[y]:
            self.root[x] += self.root[y]
            self.root[y] = x
        else:
            self.root[y] += self.root[x]
            self.root[x] = y
            if self.rnk[x] == self.rnk[y]:
                self.rnk[y] += 1

    def isSameGroup(self, x, y):
        return self.find_root(x) == self.find_root(y)

    def size(self, x):
        return -self.root[self.find_root(x)]


t = int(input())
for _ in range(t):
    N, M, a, b = map(int, input().split())
    edge = []
    for _ in range(M):
        u, v = map(int, input().split())
        edge.append((u, v))
    UF_a = UnionFind(N)
    UF_b = UnionFind(N)
    for u, v in edge:
        if u != a and v != a:
            UF_a.unite(u, v)
        if u != b and v != b:
            UF_b.unite(u, v)
    c = N-1 - UF_a.size(b)
    d = N-1 - UF_b.size(a)
    print(c*d)