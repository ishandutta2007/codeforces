mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    class UnionFind():
        def __init__(self, n):
            self.n = n
            self.root = [-1] * (n + 1)
            self.rnk = [0] * (n + 1)

        def find_root(self, x):
            while self.root[x] >= 0:
                x = self.root[x]
            return x

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

    N = int(input())
    adj = [[] for _ in range(N+1)]
    UF0 = UnionFind(N+1)
    UF1 = UnionFind(N+1)
    for _ in range(N-1):
        a, b, c = map(int, input().split())
        adj[a].append((b, c))
        adj[b].append((a, c))
        if c == 0:
            UF0.unite(a, b)
        else:
            UF1.unite(a, b)

    ans = 0
    roots = set()
    for v in range(1, N+1):
        r = UF1.find_root(v)
        if r not in roots:
            roots.add(r)
            s = -UF1.root[r]
            ans += s * (s-1)
    #print(ans)

    roots = set()
    for v in range(1, N+1):
        r = UF0.find_root(v)
        if r not in roots:
            roots.add(r)
            s = -UF0.root[r]
            ans += s * (s-1)
    #print(ans)

    for v in range(1, N+1):
        W = 0
        B = 0
        flg0 = 0
        flg1 = 0
        for u, c in adj[v]:
            if flg0 and flg1:
                break
            if c == 0:
                if flg0:
                    continue
                W += UF0.size(u) - 1
                flg0 = 1
            else:
                if flg1:
                    continue
                B += UF1.size(u) - 1
                flg1 = 1
        ans += W * B
    print(ans)


if __name__ == '__main__':
    main()