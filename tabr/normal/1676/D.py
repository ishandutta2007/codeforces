import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        b = list(map(int, input().split()))
        a.append(b)
    x = [0] * (n + m)
    y = [0] * (n + m)
    for i in range(n):
        for j in range(m):
            x[i + j] += a[i][j]
            y[i - j + m] += a[i][j]
    ans = 0
    for i in range(n):
        for j in range(m):
            ans = max(ans, x[i + j] + y[i - j + m] - a[i][j])
    print(ans)