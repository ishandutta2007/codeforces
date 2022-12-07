mod = 1000000007
eps = 10**-9
inf = 10**18


def main():
    import sys
    input = sys.stdin.readline

    N, r1, r2, r3, d = map(int, input().split())
    A = list(map(int, input().split()))

    dp = [inf] * (N+1)
    dp[0] = -d
    for i in range(N):
        a = A[i]
        dp[i+1] = min(dp[i+1], dp[i] + d + a * r1 + r3)
        if i+1 == N:
            dp[i+1] = min(dp[i+1], dp[i] + d * 3 + min(r2+r1, r1 * (a+2)))
        if i+1 < N:
            if i+2 != N:
                dp[i+2] = min(dp[i+2], dp[i] + d*4 + min(r2 + r1, r1 * (a+2)) + min(r2 + r1, r1 * (A[i+1] + 2), r1 * A[i+1] + r3))
            else:
                dp[i + 2] = min(dp[i + 2],
                                dp[i] + d * 4 + min(r2 + r1, r1 * (a + 2)) + min(r2 + r1, r1 * (A[i + 1] + 2)),
                                dp[i] + d * 3 + min(r2 + r1, r1 * (a + 2)) + r1 * A[i+1] + r3)
    print(dp[N])
    #print(dp)


if __name__ == '__main__':
    main()