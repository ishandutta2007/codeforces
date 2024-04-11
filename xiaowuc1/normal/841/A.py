n, k = (int(x) for x in raw_input().split())
from collections import defaultdict
dp = defaultdict(int)
s = raw_input()
ret = "YES"
for x in s:
    dp[x] += 1
    if dp[x] > k:
        ret = "NO"
print ret