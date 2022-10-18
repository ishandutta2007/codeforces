import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    order = []
    for i in range(n):
        order.append(a[i] * (10 ** 7) - i)
    order.sort()
    j = 0
    for ii in order:
        i = -ii % (10 ** 7)
        a[i] = j
        j += 1
    ans = 0
    f = [0] * n
    def add_value(x, v):
        while x < n:
            f[x] += v
            x = x | (x + 1)
    def get_value(x):
        v = 0
        while x >= 0:
            v += f[x]
            x = (x & (x + 1)) - 1
        return v
    for i in range(n):
        ans += i - get_value(a[i])
        add_value(a[i], 1)
    print(ans)