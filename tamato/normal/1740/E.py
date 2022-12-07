mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    P = [0, 0] + list(map(int, input().split()))

    child = [[] for _ in range(N + 1)]
    for v in range(2, N+1):
        p = P[v]
        child[p].append(v)

    dp = [0] * (N + 1)
    dp2 = [0] * (N + 1)
    for v in range(N, 0, -1):
        if not child[v]:
            dp2[v] = 1
            dp[v] = 1
        else:
            S = 0
            D = 0
            for c in child[v]:
                S += dp[c]
                D = max(D, dp2[c])
            dp2[v] = D + 1
            dp[v] = max(S, D + 1)
    print(dp[1])
    #print(dp, dp2)


if __name__ == '__main__':
    main()