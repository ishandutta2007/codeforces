import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n - 1):
        for j in reversed(range(i + 1)):
            while a[j + 1] > 0 and a[j] >= a[j + 1]:
                a[j] = a[j] // 2
                ans += 1
    for i in range(n - 1):
        if a[i] >= a[i + 1]:
            ans = -1
            break
    print(ans)