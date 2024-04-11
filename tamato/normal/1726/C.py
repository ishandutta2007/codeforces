mod = 998244353


def main():
    import sys
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

    for _ in range(int(input())):
        N = int(input())
        S = input().rstrip('\n')

        UF = UnionFind(2 * N)
        x = 0
        pair = [-1] * (2 * N)
        st = []
        for i, s in enumerate(S):
            if s == "(":
                x += 1
                st.append(i)
            else:
                x -= 1
                j = st.pop()
                UF.unite(i+1, j+1)
                pair[i] = j
                if j != 0:
                    if S[j - 1] == ")":
                        UF.unite(i+1, pair[j - 1] + 1)

        ans = 0
        for v in range(1, 2 * N + 1):
            if UF.find_root(v) == v:
                ans += 1
        print(ans)


if __name__ == '__main__':
    main()