import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    s = input()
    i = 0
    ans = "YES"
    while i < n:
        if s[i] == 'W':
            i += 1
            continue
        j = i
        found_b = False
        found_r = False
        while j < n and s[j] != 'W':
            if s[j] == 'B':
                found_b = True
            if s[j] == 'R':
                found_r = True
            j += 1
        i = j
        if not found_b or not found_r:
            ans = "NO"
    print(ans)