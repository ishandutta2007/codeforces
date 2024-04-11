import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    a = list(s)
    k = min(k, 25)
    c = [0] * 26
    for i in range(n):
        if k == 0:
            break
        b = ord(a[i]) - ord('a')
        while b > 0:
            if c[b] == 0:
                if k > 0:
                    k -= 1
                    c[b] = 1
                else:
                    break
            b -= 1
    for i in range(n):
        while a[i] != 'a':
            b = ord(a[i]) - ord('a')
            if c[b] == 1:
                a[i] = chr(ord(a[i]) - 1)
            else:
                break
    print(*a, sep="", end="")