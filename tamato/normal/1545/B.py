mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    # comb init
    nmax = 10 ** 5 + 10  # change here
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

    for _ in range(int(input())):
        N = int(input())
        S = input().rstrip('\n')

        x = y = 0
        cnt = 0
        prev = "!"
        for i, s in enumerate(S):
            if s == "1":
                cnt += 1
            else:
                y += 1
                if prev == "1":
                    x += cnt // 2
                cnt = 0
            prev = s
        x += cnt // 2
        print(comb(x+y, x))


if __name__ == '__main__':
    main()