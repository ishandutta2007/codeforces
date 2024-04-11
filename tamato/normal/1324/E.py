def main():
    import sys
    input = sys.stdin.readline

    N, H, L, R = map(int, input().split())
    A = list(map(int, input().split()))

    dp = [[-1] * H for _ in range(N+1)]
    dp[0][0] = 0
    for i, a in enumerate(A):
        for t in range(H):
            if dp[i][t] >= 0:
                dp[i+1][(t+a)%H] = max(dp[i+1][(t+a)%H], dp[i][t] + int(L <= (t+a)%H <= R))
                dp[i + 1][(t + a-1) % H] = max(dp[i + 1][(t + a-1) % H], dp[i][t] + int(L <= (t + a-1) % H <= R))
    print(max(dp[-1]))



if __name__ == '__main__':
    main()