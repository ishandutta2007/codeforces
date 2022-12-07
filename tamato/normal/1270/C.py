import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    N = int(input())
    A = list(map(int, input().split()))

    s = sum(A)
    x = 0
    for a in A:
        x ^= a
    print(2)
    print(x, x+s)