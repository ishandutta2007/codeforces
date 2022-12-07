mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    # comb init
    nmax = 3 * 10 ** 5 + 10  # change here
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

    F = [1, 1]
    for i in range(2, 3 * 10 ** 5 + 1):
        F.append((F[-1] + (i - 1) * F[-2]) % mod)

    for _ in range(int(input())):
        N = int(input())
        ans = 0
        tmp = 1
        pow2 = 1
        for k in range(N+1):
            if N - 4 * k < 0:
                break
            ans = (ans + ((comb(N - 2 * k, 2 * k) * F[N - 4 * k]) % mod * (tmp * pow2) % mod) % mod) % mod
            tmp = (tmp * (2 * k + 1)) % mod
            pow2 = (pow2 * 2) % mod
        print(ans)


if __name__ == '__main__':
    main()