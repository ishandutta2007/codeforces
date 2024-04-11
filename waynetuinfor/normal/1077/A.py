t = int(input())
for i in range(t):
    a, b, k = list(map(int, input().split()))
    ans = (a - b) * (k // 2)
    if k % 2 == 1:
        ans += a
    print(ans)