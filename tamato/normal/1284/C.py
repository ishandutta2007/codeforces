def main():
    import sys
    input = sys.stdin.readline

    N, mod = map(int, input().split())
    nmax = N + 1  # change here
    fac = [0] * (nmax + 1)
    fac[0] = 1
    fac[1] = 1
    for i in range(2, nmax):
        fac[i] = fac[i - 1] * i % mod

    ans = 0
    for k in range(1, N+1):
        ans = (ans + (((N-k+1) ** 2)%mod * (fac[N-k] * fac[k])%mod)%mod) % mod
    print(ans)


if __name__ == '__main__':
    main()