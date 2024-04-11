import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    c = [0] * 31
    for i in a:
        for j in range(31):
            if (i & (1 << j)) == 0:
                c[j] += 1
    ans = 0
    for i in reversed(range(31)):
        if c[i] <= k:
            k -= c[i]
            c[i] = 0
        if c[i] == 0:
            ans += 1 << i
    print(ans)