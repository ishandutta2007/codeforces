n = int(input())
p = list(map(int, input().split()))

dp = [0] * (n + 1)
for x in p:
    dp[x] = 1 + dp[x - 1]

res = n - max(dp)
print(res)