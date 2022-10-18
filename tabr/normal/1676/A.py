import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    s = input()
    a = 0
    b = 0
    for i in range(3):
        a += ord(s[i]) - ord('0')
        b += ord(s[i + 3]) - ord('0')
    if a == b:
        print("YES")
    else:
        print("NO")