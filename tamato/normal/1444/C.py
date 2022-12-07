import os
import sys
from atexit import register
from io import BytesIO

sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
def main():
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

        def unite_root(self, x, y):
            # assert self.root[x] < 0 and self.root[y] < 0
            if self.rnk[x] > self.rnk[y]:
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

    N, M, K = map(int, input().split())
    C = [0] + list(map(int, input().split()))
    V_color = [[] for _ in range(K+1)]
    for v in range(1, N+1):
        V_color[C[v]].append(v)
    E = {}
    UF = UnionFind(2 * N)
    for _ in range(M):
        a, b = map(int, input().split())
        ca, cb = C[a], C[b]
        if ca == cb:
            UF.unite(a, b + N)
            UF.unite(a + N, b)
        else:
            if ca > cb:
                ca, cb = cb, ca
            c_ab = ca * (K+1) + cb
            if c_ab in E:
                E[c_ab].append((a, b))
            else:
                E[c_ab] = [(a, b)]

    ok_color_num = 0
    ok_color = [0] * (K+1)
    root_c = [set() for _ in range(K+1)]
    for c in range(1, K+1):
        ok = 1
        for v in V_color[c]:
            r1 = UF.find_root(v)
            r2 = UF.find_root(v+N)
            if r1 == r2:
                ok = 0
                break
            else:
                root_c[c].add(min(r1, r2))
        if ok:
            ok_color_num += 1
            ok_color[c] = 1
        else:
            for v in V_color[c]:
                UF.root[v] = -1

    R = [-1] * (N*2+1)
    for v in range(1, 2*N+1):
        R[v] = UF.find_root(v)

    ans = (ok_color_num - 1) * ok_color_num // 2
    root_ori = UF.root[:]
    for c_ab in E:
        ca, cb = divmod(c_ab, K+1)
        if ok_color[ca] * ok_color[cb] == 0:
            continue

        ok = 1
        for a, b in E[c_ab]:
            ra = R[a]
            rb = R[b]
            if ra <= N:
                ra2 = ra + N
            else:
                ra2 = ra - N
            if rb <= N:
                rb2 = rb + N
            else:
                rb2 = rb - N
            r_ra = UF.find_root(ra)
            r_rb2 = UF.find_root(rb2)
            if r_ra != r_rb2:
                UF.unite_root(r_ra, r_rb2)
                r_ra2 = UF.find_root(ra2)
                r_rb = UF.find_root(rb)
                if r_ra2 == r_rb:
                    ok = 0
                    break
                else:
                    UF.unite_root(r_ra2, r_rb)
        """
        if len(root_c[ca]) > len(root_c[cb]):
            ca, cb = cb, ca
        for v in root_c[ca]:
            if UF.isSameGroup(v, v+N):
                ok = 0
                break
        """
        if ok == 0:
            ans -= 1
        for v in root_c[ca]:
            UF.root[v] = root_ori[v]
            UF.root[v+N] = root_ori[v]
        for v in root_c[cb]:
            UF.root[v] = root_ori[v]
            UF.root[v+N] = root_ori[v]
    print(ans)


if __name__ == '__main__':
    main()