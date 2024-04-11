n = int(input())
a = list(map(int, input().split()))

f = {}
ans = n - 1
for x in a:
    f[x] = f.get(x, 0) + 1
    ans = min(ans, n - f[x])

print(ans)