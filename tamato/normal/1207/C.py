def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, a, b = map(int, input().split())
        S = input().rstrip('\n')

        dp = [[0] * 2 for _ in range(N+1)]
        inf = int(float(10**20))
        dp[0][0] = b
        dp[0][1] = inf
        for i in range(N):
            if S[i] == '0':
                dp[i+1][0] = min(dp[i][0] + a + b, dp[i][1] + 2*a + b)
                dp[i+1][1] = min(dp[i][0] + a*2 + 2*b, dp[i][1] + a + 2*b)
            else:
                dp[i+1][0] = inf
                dp[i+1][1] = dp[i][1] + a + 2*b
        print(dp[-1][0])
        #print(dp)


if __name__ == '__main__':
    main()