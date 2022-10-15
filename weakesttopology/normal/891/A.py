from math import gcd

n = int(input())
a = list(map(int, input().split()))

ans = -1

ones = a.count(1)
g = a[0]
for x in a:
    g = gcd(g, x)

if ones > 0:
    ans = n - ones
elif g == 1:
    ans = n + n - 1
    for i in range(n):
        g = a[i]
        sz = 1
        while i + 1 < n and g > 1:
            sz += 1
            i += 1
            g = gcd(g, a[i])
        if g == 1:
            ans = min(ans, sz - 1 + n - 1)

print(ans)