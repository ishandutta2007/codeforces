n = int(input())
a = list(map(int, input().split()))

S = sum(a)
dp = [False] * (S + 1)
dp[0] = True

for x in a:
    for y in range(S - x, -1, -1):
        dp[x + y] = dp[x + y] or dp[y]

if S % 2 == 1 or not dp[S // 2]:
    print(0)
    exit()

else:
    norm = 30
    res = -1
    for i, x in enumerate(a):
        cnt = 0
        while x & 1 == 0:
            cnt += 1
            x >>= 1
        if cnt < norm:
            norm = cnt
            res = i

    print(1)
    print(res + 1)