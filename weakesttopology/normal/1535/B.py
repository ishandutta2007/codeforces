from math import gcd
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = [(x % 2, x) for x in a]
    b.sort()
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            g = gcd(b[i][1], 2 * b[j][1])
            if g > 1:
                ans += 1
    print(ans)