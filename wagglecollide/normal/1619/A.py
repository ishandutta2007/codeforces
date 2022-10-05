import math


def input_int():
    return list(map(int, input().split()))


def solve():
    s = input()
    n = len(s)
    if n % 2 == 1:
        print('NO')
        return
    s = [s[i] for i in range(n)]
    for i in range(n // 2):
        if s[i] != s[n // 2 + i]:
            print('NO')
            return
        if i < n // 2 and s[i] != s[i + n // 2]:
            print('NO')
            return
    print('YES')


[solve() for _ in range(int(input()))]