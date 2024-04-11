#!/usr/bin/env python

from sys import stdin, stdout
input = stdin.readline

n = int(input())
a = [int(x) for x in input().split()]; a.sort()

ans = sum(a) - n

if n < 100:
    c = 2
    while (c ** min(10, n - 1) < 2 * sum(a)):
        cur = 0
        for i in range(n):
            cur += abs(a[i] - (c ** i))
        ans = min(cur, ans)
        c += 1

stdout.write(str(ans) + "\n")