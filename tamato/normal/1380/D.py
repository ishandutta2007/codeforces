mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    class SegmentTree:
        def __init__(self, A, initialize=True, segfunc=max, ident=-2000000000):
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

    N, M = map(int, input().split())
    x, k, y = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    idx = {a: i for i, a in enumerate(A)}
    i_list = [0]
    for b in B:
        i_list.append(idx[b] + 1)
    i_list.append(N+1)
    for i in range(M+1):
        if i_list[i] > i_list[i+1]:
            print(-1)
            exit()

    ST = SegmentTree(A)
    ans = 0
    for j in range(M+1):
        i1 = i_list[j]
        i2 = i_list[j+1]
        L = i2-i1-1
        if L == 0:
            continue
        ma = 0
        if i1 > 0:
            ma = max(ma, A[i1-1])
        if i2 <= N:
            ma = max(ma, A[i2-1])
        if ma > ST.query(i1+1, i2):
            cost = min(y * L, y * (L % k) + x * (L // k))
        else:
            if L < k:
                print(-1)
                exit()
            cost = min(y * (L % k) + x * (L // k), y * (L - k) + x)
        ans += cost
    print(ans)


if __name__ == '__main__':
    main()