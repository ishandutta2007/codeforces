mod = 1000000007


def main():
    import sys
    input = sys.stdin.buffer.readline

    # comb init
    nmax = 4 * 10 ** 5 + 10  # change here
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

    N = int(input())
    A = list(map(int, input().split()))

    ans = 0
    for i, a in enumerate(A):
        ans = (ans + comb(i + a, i+1))%mod
    print(ans)


if __name__ == '__main__':
    main()