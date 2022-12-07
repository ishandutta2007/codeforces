mod = 1000000007
eps = 10**-9
inf = 10**9


def main():
    import sys
    input = sys.stdin.readline

    N, K = map(int, input().split())
    S = input().rstrip('\n')
    T = input().rstrip('\n')

    if T[0] == T[1]:
        NT = min(N, S.count(T[0]) + K)
        print(NT * (NT - 1) // 2)
    else:
        dp = [[[-inf] * (K+1) for _ in range(N+1)] for _ in range(N+1)]
        dp[0][0][0] = 0
        t0 = T[0]
        t1 = T[1]
        for i in range(N):
            for nt0 in range(N+1):
                for k in range(K+1):
                    # no change
                    if S[i] == t0:
                        if nt0+1 <= N:
                            dp[i+1][nt0+1][k] = max(dp[i+1][nt0+1][k], dp[i][nt0][k])
                    elif S[i] == t1:
                        dp[i+1][nt0][k] = max(dp[i+1][nt0][k], dp[i][nt0][k] + nt0)
                    else:
                        dp[i + 1][nt0][k] = max(dp[i + 1][nt0][k], dp[i][nt0][k])
                    # change to t0
                    if k+1 <= K and nt0+1 <= N:
                        dp[i+1][nt0+1][k+1] = max(dp[i+1][nt0+1][k+1], dp[i][nt0][k])
                    # change to t1
                    if k+1 <= K:
                        dp[i+1][nt0][k+1] = max(dp[i+1][nt0][k+1], dp[i][nt0][k] + nt0)
        ans = -inf
        for nt0 in range(N+1):
            for k in range(K+1):
                ans = max(ans, dp[-1][nt0][k])
        print(ans)


if __name__ == '__main__':
    main()