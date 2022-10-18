import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    w = list(map(int, input().split()))
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i + 1] = pref[i] + w[i]
    ans = 0
    a = {}
    for i in reversed(range(n)):
        if pref[i + 1] in a.keys():
            ans = max(ans, a[pref[i + 1]] + i + 1)
        a[pref[n] - pref[i]] = n - i
    print(ans)