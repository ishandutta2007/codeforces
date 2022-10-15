n = int(input())
a = list(map(int, input().split()))

inf = 10**18
dp = [0]

for x in a:
    dp.append(-inf)
    for k in reversed(range(len(dp) - 1)):
        y = dp[k]
        if y + x >= 0:
            dp[k + 1] = max(dp[k + 1], y + x)
    if x >= 0:
        dp[1] = max(dp[1], x)

ans = 0
while ans < n and dp[ans + 1] >= 0:
    ans += 1
print(ans)