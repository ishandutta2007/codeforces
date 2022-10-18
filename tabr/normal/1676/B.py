import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(sum(a) - n * min(a))