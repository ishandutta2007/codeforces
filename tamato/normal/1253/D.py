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


def main():
    n, m = map(int, input().split())
    UF = UnionFind(n)
    edges = []
    for _ in range(m):
        a, b = map(int, input().split())
        UF.unite(a, b)
        a, b = min(a, b), max(a, b)
        edges.append((a, b))

    edges.sort(key=lambda x: x[0])

    seen = -1
    ans = 0
    for a, b in edges:
        if seen < b:
            for c in range(max(seen+1, a+1), b):
                if not UF.isSameGroup(a, c):
                    ans += 1
                    UF.unite(a, c)
            seen = b
    print(ans)


if __name__ == '__main__':
    main()