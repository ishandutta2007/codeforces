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
    l = [0] * n
    ll = read_int_list()
    for i in xrange(n):
        curr = ll[i] - 1
        l[curr] = i
    ret = 0
    for i in xrange(n-1):
        ret += abs(l[i+1] - l[i])
    print ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()