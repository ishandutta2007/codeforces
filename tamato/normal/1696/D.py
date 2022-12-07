mod = 998244353


def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    class SegmentTree:
        def __init__(self, A, initialize=True, segfunc=min, ident=2000000000):
            self.N = len(A)
            self.LV = (self.N - 1).bit_length()
            self.N0 = 1 << self.LV
            self.segfunc = segfunc
            self.ident = ident
            if initialize:
                self.data = [self.ident] * self.N0 + A + [self.ident] * (self.N0 - self.N)
                for i in range(self.N0 - 1, 0, -1):
                    self.data[i] = segfunc(self.data[i * 2], self.data[i * 2 + 1])
            else:
                self.data = [self.ident] * (self.N0 * 2)

        def update(self, i, x):
            i += self.N0 - 1
            self.data[i] = x
            for _ in range(self.LV):
                i >>= 1
                self.data[i] = self.segfunc(self.data[i * 2], self.data[i * 2 + 1])

        def get(self, i):
            return self.data[i + self.N0 - 1]

        # open interval [l, r)
        def query(self, l, r):
            l += self.N0 - 1
            r += self.N0 - 1
            ret_l = self.ident
            ret_r = self.ident
            while l < r:
                if l & 1:
                    ret_l = self.segfunc(ret_l, self.data[l])
                    l += 1
                if r & 1:
                    ret_r = self.segfunc(self.data[r - 1], ret_r)
                    r -= 1
                l >>= 1
                r >>= 1
            return self.segfunc(ret_l, ret_r)

        # return smallest i(l <= i < r) s.t. check(A[i]) == True
        def binsearch(self, l, r, check):
            if not check(self.query(l, r)):
                return r
            l += self.N0 - 1
            val = self.ident
            while True:
                if check(self.segfunc(val, self.data[l])):
                    break
                if l & 1:
                    val = self.segfunc(val, self.data[l])
                    l += 1
                l >>= 1
            while l < self.N0:
                newval = self.segfunc(val, self.data[l * 2])
                if not check(newval):
                    val = newval
                    l = (l << 1) + 1
                else:
                    l <<= 1
            return l - self.N0 + 1

    class Bit:
        def __init__(self, n):
            self.size = n
            self.tree = [0] * (n + 1)

        def sum(self, i):
            s = 0
            while i > 0:
                s += self.tree[i]
                i -= i & -i
            return s

        def add(self, i, x):
            while i <= self.size:
                self.tree[i] += x
                i += i & -i

        def lower_bound(self, w):
            if w <= 0:
                return 0
            x = 0
            k = 1 << (self.size.bit_length() - 1)
            while k:
                if x + k <= self.size and self.tree[x + k] < w:
                    w -= self.tree[x + k]
                    x += k
                k >>= 1
            return x + 1

    for _ in range(int(input())):
        N = int(input())
        P = list(map(int, input().split()))

        adj = [[] for _ in range(N+1)]

        idx = [0] * (N+1)
        for i, p in enumerate(P):
            idx[p] = i + 1
        ST_min = SegmentTree(P, segfunc=min, ident=N+1)
        ST_max = SegmentTree(P, segfunc=max, ident=0)

        P = [0] + P
        bit = Bit(N)
        for p in range(1, N+1):
            i = idx[p]
            bit.add(i, 1)
            if i == N:
                continue
            if P[i+1] < p:
                continue
            j = bit.lower_bound(bit.sum(i) + 1)
            ma = ST_max.query(i+1, j)
            i_max = idx[ma]
            adj[i].append(i_max)

        bit = Bit(N)
        for p in range(N, 0, -1):
            i = idx[p]
            bit.add(i, 1)
            if i == N:
                continue
            if P[i + 1] > p:
                continue
            j = bit.lower_bound(bit.sum(i) + 1)
            mi = ST_min.query(i + 1, j)
            i_min = idx[mi]
            adj[i].append(i_min)

        que = deque()
        que.append(1)
        seen = [-1] * (N+1)
        seen[1] = 0
        while que:
            v = que.popleft()
            for u in adj[v]:
                if seen[u] == -1:
                    seen[u] = seen[v] + 1
                    que.append(u)

        print(seen[N])


if __name__ == '__main__':
    main()