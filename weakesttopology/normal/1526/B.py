N = 10 ** 5
dp = [False] * N
dp[0] = True
for x in range(N):
    if not dp[x]:
        continue
    if x + 11 < N:
        dp[x + 11] = True
    if x + 111 < N:
        dp[x + 111] = True

t = int(input())
for _ in range(t):
    x = int(input())
    print('YES' if x >= N or dp[x] else 'NO')