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

def get(x, y, m):
    ll = [x-m, x+m]
    rr = [y-m, y+m]
    left = min([x*y for x in ll for y in rr])
    right = max([x*y for x in ll for y in rr])
    return (left, right)

def touches(a, b):
    if a[0] <= b[0]:
        return a[1] >= b[0]
    return b[1] >= a[0]

def can(a, b, c, d, m):
    l = get(a, d, m)
    r = get(b, c, m)
    if touches(l, r):
        return True
    return False

def solve():
    a, b = read_floats()
    c, d = read_floats()
    l = 0
    r = 1e18
    for ___ in xrange(1000):
        m = (l+r) / 2
        if can(a, b, c, d, m):
            r = m
        else:
            l = m
    print l

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()