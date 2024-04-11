mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, K = map(int, input().split())

    comb = [1] * (2*K+1)
    for k in range(1, 2*K+1):
        comb[k] = (comb[k-1] * (N-k+1) * pow(k, mod-2, mod))%mod

    fac = [1] * (2*K+1)
    finv = [1] * (2*K+1)
    for i in range(1, 2*K+1):
        fac[i] = (fac[i-1] * i)%mod
        finv[i] = (finv[i-1] * pow(i, mod-2, mod))%mod

    combK = [[0] * (2*K+1) for _ in range(2*K+1)]
    for n in range(2*K+1):
        for k in range(2*K+1):
            combK[n][k] = (fac[n] * (finv[k] * finv[n-k])%mod)%mod

    dp = [[0] * (2*K+1) for _ in range(K+1)]
    for j in range(1, 2*K+1):
        dp[0][j] = 1
    for i in range(1, K+1):
        for j in range(1, 2*K+1):
            dp[i][j] = (dp[i][j-1] + (dp[i-1][j-1] * (j-1))%mod)%mod
    dp2 = [[0] * (2*K+1) for _ in range(K+1)]
    for i in range(1, K+1):
        for j in range(1, 2*K+1):
            for k in range(j+1):
                if k&1:
                    dp2[i][j] = (dp2[i][j] - (dp[i][j-k] * combK[j][k])%mod)%mod
                else:
                    dp2[i][j] = (dp2[i][j] + (dp[i][j - k] * combK[j][k])%mod) % mod
    ans = [0] * (K+1)
    ans[0] = 1
    ans[1] = comb[2]
    for k in range(2, K+1):
        ans[k] = ans[k-2]
        for j in range(K*2+1):
            ans[k] = (ans[k] + (dp2[k][j] * comb[j])%mod)%mod
    print(*ans[1:])


if __name__ == '__main__':
    main()