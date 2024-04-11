mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    # comb init
    # mod = 1000000007
    nmax = 100  # change here
    fac = [0] * nmax
    finv = [0] * nmax
    inv = [0] * nmax
    fac[0] = 1
    fac[1] = 1
    finv[0] = 1
    finv[1] = 1
    inv[1] = 1
    for i in range(2, nmax):
        fac[i] = fac[i - 1] * i % mod
        inv[i] = mod - inv[mod % i] * (mod // i) % mod
        finv[i] = finv[i - 1] * inv[i] % mod

    def comb(n, r):
        if n < r:
            return 0
        else:
            return (fac[n] * ((finv[r] * finv[n - r]) % mod)) % mod

    def PrimeDecomposition(N):
        ret = {}
        n = int(N ** 0.5)
        for d in range(2, n + 1):
            while N % d == 0:
                if d not in ret:
                    ret[d] = 1
                else:
                    ret[d] += 1
                N //= d
            if N == 1:
                break
        if N != 1:
            ret[N] = 1
        return ret

    D = int(input())
    PD = PrimeDecomposition(D)
    P = list(PD.keys())
    np = len(P)

    ans_all = []
    for _ in range(int(input())):
        u, v = map(int, input().split())
        pos = []
        neg = []
        for p in P:
            up = 0
            while u % p == 0:
                up += 1
                u //= p
            vp = 0
            while v % p == 0:
                vp += 1
                v //= p

            if up > vp:
                pos.append(up - vp)
            elif up < vp:
                neg.append(vp - up)
        ans = 1
        if pos:
            ans = (ans * fac[sum(pos)])%mod
            for x in pos:
                ans = (ans * finv[x])%mod
        if neg:
            ans = (ans * fac[sum(neg)]) % mod
            for x in neg:
                ans = (ans * finv[x]) % mod
        ans_all.append(ans)
    print(*ans_all, sep="\n")


if __name__ == '__main__':
    main()