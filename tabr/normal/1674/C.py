import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    s = input()
    t = input()
    s = s[:-1]
    t = t[:-1]
    if t == "a":
        print(1)
    elif len(t) > 1 and 'a' in t:
        print(-1)
    else:
        cnt = 0
        for c in s:
            if c == 'a':
                cnt += 1
        print(1 << cnt)