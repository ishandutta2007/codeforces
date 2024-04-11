mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split())) + [0]
    A.sort()

    dp = [[0] * (i+1) for i in range(N+1)]
    dp[0][0] = 1
    l = 0
    for i in range(1, N+1):
        for ll in range(l+1, i):
            if A[ll] * 2 <= A[i]:
                l = ll
            else:
                break
        for j in range(1, l+2):
            dp[i][j] = (dp[l][j-1] + (dp[i][j-1] * (l-j+2))%mod)%mod
        for j in range(i):
            dp[i][j] = (dp[i-1][j] + dp[i][j])%mod
    print(dp[-1][-1])


if __name__ == '__main__':
    main()