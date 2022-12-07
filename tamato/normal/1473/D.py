mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

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

    for _ in range(int(input())):
        N, M = map(int, input().split())
        S = input().rstrip('\n')

        cs = [0] * (N+1)
        for i, s in enumerate(S):
            if s == "+":
                cs[i+1] = cs[i] + 1
            else:
                cs[i+1] = cs[i] - 1
        ST_min = SegmentTree(cs)
        ST_max = SegmentTree(cs, segfunc=max, ident=-2*10**9)

        for _ in range(M):
            l, r = map(int, input().split())
            x = cs[l-1]
            mi = min(ST_min.query(1, l+1), x + ST_min.query(r+1, N+2) - cs[r])
            ma = max(ST_max.query(1, l+1), x + ST_max.query(r+1, N+2) - cs[r])
            print(ma - mi + 1)


if __name__ == '__main__':
    main()