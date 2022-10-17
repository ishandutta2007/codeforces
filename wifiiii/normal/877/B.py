s = input()
n = len(s)
dp = [[0] * (n + 1) for _ in range(3)]
for i in range(n):
    dp[0][i + 1] = dp[0][i] + (1 if s[i] == 'b' else 0)
    dp[1][i + 1] = min(dp[0][i], dp[1][i]) + (1 if s[i] == 'a' else 0)
    dp[2][i + 1] = min(dp[1][i], dp[2][i]) + (1 if s[i] == 'b' else 0)
print(n - min(dp[0][n], dp[1][n], dp[2][n]))