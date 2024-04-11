input = raw_input
range = xrange

s = [ord(x) - ord('a') for x in input()]

cnt = [0] * (1 << 20)
dp = [0] * (1 << 20)

for i in range(len(s)):
    ma = 0
    for j in range(min(20, len(s) - i)):
        if (ma & (1 << s[i + j - 1])) == 0:
            ma ^= 1 << s[i + j - 1]
            cnt[ma] = True
        else:
            break

for i in range(1 << 20):
    dp[i] = 0 if not cnt[i] else bin(i).count('1')
for i in range(20):
    for j in range(1 << 20):
        if j & (1 << i):
            dp[j] = max(dp[j], dp[j ^ (1 << i)])

ans = 0
for i in range(1 << 20):
    ans = max(ans, dp[i] + dp[((1 << 20) - 1) ^ i])
print ans