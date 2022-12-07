mod = 1000000007
eps = 10**-9


def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.buffer.readline

    # min
    def STfunc(a, b):
        if a > b:
            return a
        else:
            return b

    # 0-indexed[l, r)
    class SparseTable():
        def __init__(self, A):
            # A: 
            self.N = len(A)
            self.K = self.N.bit_length() - 1
            self.table = [0] * (self.N * (self.K + 1))
            for i, a in enumerate(A):
                self.table[i] = a
            for k in range(1, self.K + 1):
                for i in range(self.N):
                    j = i + (1 << (k - 1))
                    if j <= self.N - 1:
                        self.table[i + k * self.N] = STfunc(self.table[i + (k - 1) * self.N],
                                                            self.table[j + (k - 1) * self.N])

        def query(self, l, r):
            # [l, r)
            k = (r - l).bit_length() - 1
            return STfunc(self.table[l + k * self.N], self.table[r - (1 << k) + k * self.N])

    for t in range(int(input())):
        N, K = map(int, input().split())
        X = list(map(int, input().split()))
        Y = list(map(int, input().split()))

        X.sort()
        r = 0
        num = [0] * N
        R = [0] * N
        for l in range(N):
            if r < N:
                while X[l] + K >= X[r]:
                    r += 1
                    if r == N:
                        break
            num[l] = r - l
            R[l] = r
        ST = SparseTable(num)
        ans = 0
        for l in range(N-1, -1, -1):
            r = R[l]
            ans = max(ans, num[l] + num[r-1] - 1)
            if r < N:
                ans = max(ans, num[l] + ST.query(r, N))
        print(ans)


if __name__ == '__main__':
    main()