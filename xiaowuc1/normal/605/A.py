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
    d = dict()
    for i in xrange(n):
        d[l[i]] = i
    ret = 1

    curr = 1
    index = d[1]
    for i in xrange(2, n+1):
        if d[i] > index:
            curr += 1
            ret = max(ret, curr)
        else:
            curr = 1
        index = d[i]
    print n - ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()