# from functools import cache


n, a, b, c = list(map(int, input().split()))


dp = [-1 for i in range(8000)]
def f(x):
    dp[0] = 0
    for i in range(1, x + 1):
        dp[i] = -int(1e18)
        for j in [i - a, i - b, i - c]:
            if j < 0:
                continue
            dp[i] = max(dp[i], dp[j] + 1)
    return dp[x]


print(f(n))