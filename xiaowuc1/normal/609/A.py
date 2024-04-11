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
    size = read_int()
    l = []
    for _ in xrange(n):
        l.append(read_int())
    l.sort()
    l = l[::-1]
    ret = 0
    while size > 0:
        size -= l[ret]
        ret += 1
    print ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()