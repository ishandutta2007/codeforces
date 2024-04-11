### TEMPLATE BEGIN

from collections import defaultdict
from math import sqrt

def read_int():
    return int(raw_input())

def read_ints():
    return (int(x) for x in raw_input().split())

def read_int_list():
    return [int(x) for x in raw_input().split()]

def read_float():
    return float(raw_input())

def read_floats():
    return (float(x) for x in raw_input().split())

def read_float_list():
    return [float(x) for x in raw_input().split()]

def read_list():
    return [x for x in raw_input().split()]

def read_line():
    return raw_input()

### TEMPLATE END

def gcd(x, y):
    if x == 0:
        return y
    if y == 0:
        return x
    return gcd(y, x%y)

def solve():
    n = read_int()
    l = [read_int_list() for x in xrange(n)]
    ret = 0
    for i in xrange(n):
        dp = defaultdict(int)
        for j in xrange(n):
            if j <= i:
                continue
            a = l[j][0] - l[i][0]
            b = l[j][1] - l[i][1]
            g = gcd(abs(a), abs(b))
            a /= g
            b /= g
            if (a < 0) or (a == 0 and b < 0):
                a = -a
                b = -b
            dp[(a, b)] += 1
        ret += (n-i-1) * (n-i-2) / 2
        for key in dp:
            ret -= dp[key] * (dp[key]-1) / 2
    print ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()