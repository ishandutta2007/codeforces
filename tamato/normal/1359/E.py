mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    # comb init
    nmax = 10 ** 6 + 10  # change here
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

    N, K = map(int, input().split())
    ans = 0
    for i in range(1, N+1):
        n = N // i - 1
        ans = (ans + comb(n, K-1))%mod
    print(ans)


if __name__ == '__main__':
    main()