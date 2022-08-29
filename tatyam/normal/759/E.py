import sys
input = sys.stdin.readline
MOD = 1000000007

n = int(input())
a = list(map(int, input().split()))
a.append(1)
b = list(map(int, input().split()))
m = int(input())
dp = [1]
for x, y in zip(b, a):
    dp.extend([0] * x)
    for i in range(len(dp) - 1):
        dp[i + 1] += dp[i]
        if dp[i + 1] >= MOD:
            dp[i + 1] -= MOD
    for i in range(len(dp) - 1, x, -1):
        dp[i] -= dp[i - x - 1]
        if dp[i] < 0:
            dp[i] += MOD
    if y > 1:
        dp = dp[m % y :: y]
        m //= y
if len(dp) <= m:
    print(0)
else:
    print(dp[m])