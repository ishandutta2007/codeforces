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

def read_line():
    return raw_input()

### TEMPLATE END

def solve():
    a = read_line()
    b = read_line()
    ret = 0
    pref = [0]
    for _ in xrange(len(b)):
        pref.append(pref[-1])
        if b[_] == '1':
            pref[-1] += 1
    for _ in xrange(len(a)):
        ones = pref[_ + len(b) - len(a) + 1] - pref[_]
        zeros = (len(b) - len(a) + 1) - ones
        if a[_] == '0':
            ret += ones
        else:
            ret += zeros
    print ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()