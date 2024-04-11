mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    S = input().rstrip('\n')
    S = S[::-1]
    T = input().rstrip('\n')
    NS = len(S)
    NT = len(T)

    dp = [[0] * (NT+1) for _ in range(NS+1)]
    dp[0][0] = 1
    for i in range(NS):
        s = S[i]
        for j in range(NT+1):
            # front
            if j == 0:
                if i != NS-1:
                    if T[0] == s and dp[i][0]:
                        dp[i+1][1] = (dp[i+1][1] + dp[i][0] + min(i, NS-NT))%mod
                else:
                    if T[0] == s and dp[i][0]:
                        dp[i+1][-1] = (dp[i+1][-1] + dp[i][0] + NS-NT)%mod
            elif j == NT:
                dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod
            else:
                if i != NS-1:
                    if s == T[j]:
                        dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j])%mod
                else:
                    if s == T[j]:
                        dp[i + 1][-1] = (dp[i + 1][-1] + dp[i][j]) % mod
            # back
            k = NS - (i-j) - 1
            if k >= NT:
                dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod
            else:
                if T[k] == s:
                    if i != NS-1:
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod
                    else:
                        dp[i + 1][-1] = (dp[i + 1][-1] + dp[i][j]) % mod
                        if k == 0 and dp[i][j]:
                            dp[i+1][-1] = (dp[i+1][-1] + (NS-NT))%mod
    print(dp[-1][-1]%mod)
    #[print(i, dp[i]) for i in range(NS+1)]


if __name__ == '__main__':
    main()