mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    dp = [512] * 512
    dp[0] = 0
    for a in A:
        for x in range(512):
            x_new = x ^ a
            if dp[x] < a:
                dp[x_new] = min(dp[x_new], a)
        dp[a] = min(dp[a], a)
    ans = []
    for x in range(512):
        if dp[x] < 512:
            ans.append(x)
    print(len(ans))
    print(*ans)


if __name__ == '__main__':
    main()