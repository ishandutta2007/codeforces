mod = 1000000007
eps = 10**-9


def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.buffer.readline

    def calc(r, g, b):
        return (r-g)**2 + (g-b)**2 + (b-r)**2

    for _ in range(int(input())):
        NR, NG, NB = map(int, input().split())
        R = list(map(int, input().split()))
        G = list(map(int, input().split()))
        B = list(map(int, input().split()))
        R.sort()
        B.sort()
        G.sort()
        ans = float('inf')

        #RGB
        L = R[:]
        M = G[:]
        S = B[:]
        for m in M:
            il = bisect_left(L, m)
            if il == len(L):
                continue
            l = L[il]
            is_ = bisect_left(S, m+1)
            if is_ == 0:
                continue
            s = S[is_-1]
            ans = min(ans, calc(l, m, s))

        # RBG
        L = R[:]
        M = B[:]
        S = G[:]
        for m in M:
            il = bisect_left(L, m)
            if il == len(L):
                continue
            l = L[il]
            is_ = bisect_left(S, m + 1)
            if is_ == 0:
                continue
            s = S[is_-1]
            ans = min(ans, calc(l, m, s))

        # GRB
        L = G[:]
        M = R[:]
        S = B[:]
        for m in M:
            il = bisect_left(L, m)
            if il == len(L):
                continue
            l = L[il]
            is_ = bisect_left(S, m + 1)
            if is_ == 0:
                continue
            s = S[is_ - 1]
            ans = min(ans, calc(l, m, s))

        # GBR
        L = G[:]
        M = B[:]
        S = R[:]
        for m in M:
            il = bisect_left(L, m)
            if il == len(L):
                continue
            l = L[il]
            is_ = bisect_left(S, m + 1)
            if is_ == 0:
                continue
            s = S[is_ - 1]
            ans = min(ans, calc(l, m, s))

        # BRG
        L = B[:]
        M = R[:]
        S = G[:]
        for m in M:
            il = bisect_left(L, m)
            if il == len(L):
                continue
            l = L[il]
            is_ = bisect_left(S, m + 1)
            if is_ == 0:
                continue
            s = S[is_ - 1]
            ans = min(ans, calc(l, m, s))

        # BGR
        L = B[:]
        M = G[:]
        S = R[:]
        for m in M:
            il = bisect_left(L, m)
            if il == len(L):
                continue
            l = L[il]
            is_ = bisect_left(S, m + 1)
            if is_ == 0:
                continue
            s = S[is_ - 1]
            ans = min(ans, calc(l, m, s))

        print(ans)


if __name__ == '__main__':
    main()