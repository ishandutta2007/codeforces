import sys
import math
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,h = list(map(int, input().split()))
    a = list(map(int, input().split()))
    low,high = 1,10**18
    while low < high:
        mid = (low + high) // 2
        damage = 0
        max_damage = -float('inf')
        for i in range(n):
            if a[i] - max_damage > mid:
                damage += mid
                max_damage = a[i]
            else:
                damage += (a[i] - max_damage)
                max_damage = a[i]
        if damage >= h:
            high = mid
        else:
            low = mid + 1
    print(low)