mod = 1000000007
eps = 10**-9
inf = 1000000000.0


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = []
    B = []
    for _ in range(N):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)

    vmax = sum(A)
    dp = [[-inf] * (vmax+1)]
    dp[0][0] = 0.
    for i in range(N):
        a = A[i]
        b = B[i]
        dp_new = [[-inf] * (vmax+1) for _ in range(i+2)]
        for j in range(i+1):
            for v in range(vmax + 1):
                # not use
                dp_new[j][v] = max(dp_new[j][v], dp[j][v] + b / 2)
                # use
                if v + a <= vmax:
                    dp_new[j+1][v+a] = max(dp_new[j+1][v+a], dp[j][v] + b)
        dp = dp_new
    ans = [-1] * (N+1)
    for k in range(1, N+1):
        for v in range(vmax+1):
            ans[k] = max(ans[k], min(dp[k][v], v))
    print(*ans[1:])


if __name__ == '__main__':
    main()