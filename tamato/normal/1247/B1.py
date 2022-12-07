t = int(input())
for _ in range(t):
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 10000
    for i in range(n - d + 1):
        chs = a[i:i+d]
        ans = min(ans, len(set(chs)))
    print(ans)