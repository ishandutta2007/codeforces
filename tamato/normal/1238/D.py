def main():
    import sys
    input = sys.stdin.readline

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

    N = int(input())
    s = input().rstrip('\n')

    UF = UnionFind(N+1)
    for i in range(N-1):
        if s[i] == s[i+1]:
            UF.unite(i+1, i+2)
    ans = (N * (N-1)) // 2
    for i in range(N-1):
        if s[i] != s[i+1]:
            ans -= UF.size(i+1) + UF.size(i+2) - 1
    print(ans)


if __name__ == '__main__':
    main()