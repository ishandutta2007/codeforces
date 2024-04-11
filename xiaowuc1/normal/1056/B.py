from collections import defaultdict
n, m = (int(x) for x in raw_input().split())
dp = defaultdict(int)
for x in range(m):
    amt = (n-x)/m + 1
    if x == 0:
        amt -= 1
    dp[x] += amt
ret = 0
for i in range(m):
    for j in range(m):
        if (i*i + j*j) % m == 0:
            ret += dp[i] * dp[j]
print ret