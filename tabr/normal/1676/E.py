import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    a.reverse()
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i + 1] = pref[i] + a[i]
    for i in range(q):
        x = int(input())
        if pref[n] < x:
            print(-1)
        else:
            low = -1
            high = n
            while high - low > 1:
                mid = (high + low) >> 1
                if pref[mid] >= x:
                    high = mid
                else:
                    low = mid
            print(high)