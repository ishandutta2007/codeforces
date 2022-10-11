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
    ret = 2
    left = 0
    for i in xrange(n):
        if l[i] not in d:
            d[l[i]] = 0
        d[l[i]] += 1
        while len(d) > 2:
            d[l[left]] -= 1
            if d[l[left]] == 0:
                del d[l[left]]
            left += 1
        ret = max(ret, i - left + 1)
    print ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()