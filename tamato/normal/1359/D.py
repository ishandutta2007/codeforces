mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

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

    N = int(input())
    A = list(map(int, input().split()))

    cs = [0] * (N+1)
    B = []
    for i, a in enumerate(A):
        cs[i+1] = cs[i] + A[i]
        B.append((a, i+1))
    B.sort(key=lambda x: x[0], reverse=True)
    ma = SegmentTree(cs, segfunc=max, ident=-2000000000)
    mi = SegmentTree(cs)
    bit = Bit(N)
    ans = 0
    for a, i in B:
        if a <= 0:
            break
        bit.add(i, 1)
        k = bit.sum(i)
        r = bit.lower_bound(k+1)
        l = bit.lower_bound(k-1)
        ans = max(ans, ma.query(i+1, r+1) - mi.query(l+1, i+2) - a)
    print(ans)


if __name__ == '__main__':
    main()