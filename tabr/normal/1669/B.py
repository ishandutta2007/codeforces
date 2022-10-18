import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = -1
    for i in range(n - 2):
        if a[i] == a[i + 1] and a[i + 1] == a[i + 2]:
            ans = a[i]
    print(ans)