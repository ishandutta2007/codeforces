mod = 10 ** 9 + 7

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    ans = 1
    for j in range(k):
        ans = n * ans % mod
    print(ans)