import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    x, y = map(int, input().split())
    if y % x != 0:
        print("0 0")
    else:
        x = y // x
        print(1, x)