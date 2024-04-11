import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.reverse()
    for i in range(n):
        if i % 2 == 1 and a[i] > a[i - 1]:
            a[i], a[i - 1] = a[i - 1], a[i]
    a.reverse()
    ans = "YES"
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            ans = "NO"
    print(ans)