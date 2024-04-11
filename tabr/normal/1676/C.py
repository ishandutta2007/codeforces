import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n, m = map(int, input().split())
    s = []
    for i in range(n):
        t = input()
        s.append(t[:-1])
    ans = 10 ** 9
    for i in range(n):
        for j in range(i + 1, n):
            t = 0
            for k in range(m):
                t += abs(ord(s[i][k]) - ord(s[j][k]))
            ans = min(ans, t)
    print(ans)