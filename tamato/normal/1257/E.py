def main():
    import sys
    input = sys.stdin.readline

    k1, k2, k3 = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    dic = {}
    for a in A:
        dic[a] = 0
    for b in B:
        dic[b] = 1
    for c in C:
        dic[c] = 2

    N = k1+k2+k3
    dp = [[10**9] * 3 for _ in range(N+1)]
    dp[0][0] = 0
    dp[0][1] = 0
    dp[0][2] = 0
    for i in range(1, N+1):
        dp[i][0] = min(dp[i][0], dp[i-1][0] + (dic[i] != 0))
        dp[i][1] = min(dp[i][1], dp[i-1][1] + (dic[i] != 1), dp[i-1][0] + (dic[i] != 1))
        dp[i][2] = min(dp[i][2], dp[i - 1][2] + (dic[i] != 2), dp[i - 1][1] + (dic[i] != 2), dp[i - 1][0] + (dic[i] != 2))
    print(min(dp[-1]))


if __name__ == '__main__':
    main()