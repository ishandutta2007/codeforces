mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

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

    N, Q = map(int, input().split())
    q0 = []
    q1 = []
    cnt = 0
    for _ in range(Q):
        line = list(map(int, input().split()))
        if line[0] == 0:
            q0.append(line[1:])
            cnt += 1
        else:
            q1.append((line[1], cnt))

    T = len(q0)
    updated_time = [-1] * N
    imos = [[] for _ in range(N + 1)]
    for t in range(T - 1, -1, -1):
        l, r, x = q0[t]
        if x == 1:
            continue
        imos[l - 1].append(t + 1)
        imos[r].append(-(t + 1))
    bit = Bit(T + 1)
    bit.add(T + 1, 1)
    for i in range(N):
        for x in imos[i]:
            if x > 0:
                bit.add(x, 1)
            else:
                bit.add(-x, -1)
        mi = bit.lower_bound(1)
        if mi <= T:
            updated_time[i] = mi

    bit_suspect = Bit(N)
    for i in range(N):
        if updated_time[i] == -1:
            bit_suspect.add(i + 1, 1)
    ST_upd = SegmentTree(updated_time)
    upd_old = updated_time[:]

    cnt = 0
    for l, r, x in q0:
        cnt += 1
        if x == 1:
            if l > 1:
                S = bit_suspect.sum(r) - bit_suspect.sum(l - 1)
            else:
                S = bit_suspect.sum(r)
            if S == 1:
                j = bit_suspect.lower_bound(bit_suspect.sum(r))
                updated_time_new = max(cnt, ST_upd.query(l, r + 1))
                if updated_time[j - 1] == -1:
                    updated_time[j - 1] = updated_time_new
                else:
                    updated_time[j - 1] = min(updated_time[j - 1], updated_time_new)
    for x, t in q1:
        if updated_time[x - 1] == -1:
            print("N/A")
        else:
            if t >= updated_time[x - 1]:
                if upd_old[x - 1] == -1:
                    print("YES")
                else:
                    print("NO")
            else:
                print("N/A")


if __name__ == '__main__':
    main()