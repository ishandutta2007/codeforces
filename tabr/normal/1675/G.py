import sys
input = sys.stdin.readline
import math

for _ in range(1):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i + 1] = pref[i] + a[i]
    dp = [[10 ** 9 for y in range(pref[n] + 1)] for x in range(m + 1)]
    dp[m][0] = 0
    for i in range(n):
        new_dp = [[10 ** 9 for y in range(pref[n] + 1)] for x in range(m + 1)]
        for x in reversed(range(m + 1)):
            for y in range(pref[n] + 1):
                if x < m:
                    dp[x][y] = min(dp[x][y], dp[x + 1][y])
                if x + y <= pref[n]:
                    new_dp[x][x + y] = min(new_dp[x][x + y], dp[x][y] + abs(pref[i + 1] - (x + y)))
        dp, new_dp = new_dp, dp
    ans = 10 ** 9
    for i in range(m + 1):
        ans = min(ans, dp[i][pref[n]])
    print(ans)