n = int(input())
a = list(map(int, input().split()))

inf = 10 ** 10

# dp[0] = minimum if no contest in the previous day
# dp[1] = minimum if no gym in the previous day
dp = [0, 0]

# 0, nothing
# 1, contest
# 2, gym
# 3, contest and gym

for x in a:
    z = min(dp)
    if x == 0:
        dp[0] = 1 + z
        dp[1] = 1 + z
    elif x == 1:
        dp[1] = min(dp[0], dp[1] + 1)
        dp[0] = z + 1
    elif x == 2:
        dp[0] = min(dp[1], dp[0] + 1)
        dp[1] = z + 1
    else:
        dp[0], dp[1] = min(dp[1], dp[0] + 1), min(dp[0], dp[1] + 1)

print(min(dp))