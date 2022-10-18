import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = "YES"
    for i in range(n - 2):
        if a[i] % 2 != a[i + 2] % 2:
            ans = "NO"
    print(ans)