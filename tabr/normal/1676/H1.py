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
    for i in range(n):
        for j in range(i + 1, n):
            if a[i] > a[j]:
                ans += 1
    print(ans)