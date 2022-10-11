### TEMPLATE BEGIN

from collections import defaultdict

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

### TEMPLATE END

def solve():
    n = read_int()
    l = read_int_list()
    ret = 0
    for i in xrange(len(l)-1, -1, -1):
        if 2*i+3 < len(l):
            ret += abs(l[2*i+2] - l[2*i+3])
            l[i] += max(l[2*i+2], l[2*i+3])
    print ret + abs(l[0] - l[1])

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()