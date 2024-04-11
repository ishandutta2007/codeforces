from collections import defaultdict

n = int(raw_input())

l = [int(x) for x in raw_input().split()]
dp = defaultdict(int)

ans = 0

first = dict()
last = dict()

for i in xrange(n):
    x = l[i]
    dp[x] += 1
    ans = max(ans, dp[x])
    if x not in first:
        first[x] = i
    last[x] = i

l = 0
r = n-1
for x in dp:
    if dp[x] == ans and last[x] - first[x] < r - l:
        r = last[x]
        l = first[x]
print "{} {}".format(l+1, r+1)