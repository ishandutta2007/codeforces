def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    P = list(map(int, input().split()))
    A = list(map(float, input().split()))

    class LazySegTree:
        # Range add query
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
            self.lazy = [0] * (self.N0 * 2)

        def _ascend(self, i):
            for _ in range(i.bit_length() - 1):
                i >>= 1
                self.data[i] = self.segfunc(self.data[i * 2], self.data[i * 2 + 1]) + self.lazy[i]

        def _descend(self, idx):
            lv = idx.bit_length()
            for j in range(lv - 1, 0, -1):
                i = idx >> j
                x = self.lazy[i]
                if not x:
                    continue
                self.lazy[i] = 0
                self.lazy[i * 2] += x
                self.lazy[i * 2 + 1] += x
                self.data[i * 2] += x
                self.data[i * 2 + 1] += x

        # open interval [l, r)
        def add(self, l, r, x):
            l += self.N0 - 1
            r += self.N0 - 1
            l_ori = l
            r_ori = r
            while l < r:
                if l & 1:
                    self.data[l] += x
                    self.lazy[l] += x
                    l += 1
                if r & 1:
                    r -= 1
                    self.data[r] += x
                    self.lazy[r] += x
                l >>= 1
                r >>= 1
            self._ascend(l_ori // (l_ori & -l_ori))
            self._ascend(r_ori // (r_ori & -r_ori) - 1)

        # open interval [l, r)
        def query(self, l, r):
            l += self.N0 - 1
            r += self.N0 - 1
            self._descend(l // (l & -l))
            self._descend(r // (r & -r) - 1)
            ret = self.ident
            while l < r:
                if l & 1:
                    ret = self.segfunc(ret, self.data[l])
                    l += 1
                if r & 1:
                    ret = self.segfunc(self.data[r - 1], ret)
                    r -= 1
                l >>= 1
                r >>= 1
            return ret


    p2i = {}
    for i, p in enumerate(P):
        p2i[p] = i

    S = 0
    init = [0.] * N
    for i in range(1, N):
        S += A[i-1]
        init[i-1] = S
    segtree = LazySegTree(init, ident=float('inf'))
    ans = A[0]
    cnt = 0
    for p in range(1, N+1):
        i = p2i[p]
        a = A[i]
        cnt += a
        segtree.add(i+1, N, -a * 2)
        ans = min(ans, segtree.query(1, N) + cnt)
    print(int(ans))


if __name__ == '__main__':
    main()