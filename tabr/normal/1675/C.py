import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    s = input()
    n = len(s) - 1
    ans = 0
    last1 = -1
    for i in range(n):
        if s[i] == '1':
            last1 = i
    first0 = n
    for i in reversed(range(n)):
        if s[i] == '0':
            first0 = i
    for i in range(n):
        if i < last1 or first0 < i:
            continue
        ans += 1
    print(ans)