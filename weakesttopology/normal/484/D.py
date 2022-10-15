import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

dp = [0] * n
pos, neg = -10 ** 18, -10 ** 18

for i, x in enumerate(a):
    prv = 0 if i == 0 else dp[i - 1]
    dp[i] = max(neg + x, pos - x, prv)
    pos = max(pos, prv + x)
    neg = max(neg, prv - x)

print(dp[-1])