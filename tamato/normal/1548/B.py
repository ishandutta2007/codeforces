mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.buffer.readline

    # min
    def STfunc(a, b):
        return gcd(a, b)

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

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        B = []
        for i in range(N-1):
            B.append(A[i+1] - A[i])

        ST = SparseTable(B)
        ans = 1
        for i in range(N-1):
            ok = i-1
            ng = N-1
            mid = (ok + ng) // 2
            while ng - ok > 1:
                if ST.query(i, mid+1) == 1:
                    ng = mid
                else:
                    ok = mid
                mid = (ok + ng) // 2
            ans = max(ans, ok - i + 2)
            #print(i, ok)
        print(ans)
        #print(B)


if __name__ == '__main__':
    main()