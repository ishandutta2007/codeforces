def main():
    import sys
    from operator import itemgetter
    input = sys.stdin.readline

    N = int(input())
    K = N.bit_length() - 1
    A_raw = list(map(int, input().split()))

    flg = 1
    A = []
    for i, a in enumerate(A_raw):
        if flg:
            if a == -1:
                flg = 0
            else:
                A.append(0)
        else:
            A.append(A_raw[i])
    inf = 1<<40
    dp = [[inf] * (K+1) for _ in range(N)]
    dp[0][0] = 0
    for i in range(N):
        for j in range(K+1):
            if dp[i][j] < inf:
                if j < K:
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + A[N-2-i])
                if N - 2**(K-j) > i:
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j])
    print(dp[-1][-1])


if __name__ == '__main__':
    main()