import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    s = input()
    ans = 1
    for i in range(26):
        for j in range(26):
            x = ord(s[0]) - ord('a')
            y = ord(s[1]) - ord('a')
            if i != j and i * 100 + j < x * 100 + y:
                ans += 1
    print(ans)