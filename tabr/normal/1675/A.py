import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    a, b, c, x, y = map(int, input().split())
    x -= a
    y -= b
    x = max(0, x)
    y = max(0, y)
    if x + y <= c:
        print("YES")
    else:
        print("NO")