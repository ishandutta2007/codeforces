import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    m = min(l)
    for i in range(n):
        l[i] -= m
    s = sum(l)
    if s%n == 0:
        print(0)
    else:
        print(1)