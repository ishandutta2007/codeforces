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

def solve():
    height, node = read_ints()
    node -= 1
    left = True
    leftLeaf = 0
    intervalSize = 2 ** height
    ret = 0
    while intervalSize > 1:
        if left:
            ll = leftLeaf
            rr = ll + intervalSize/2
        else:
            ll = leftLeaf + intervalSize/2
            rr = ll + intervalSize/2
        if node >= ll and node < rr:
            ret += 1
            left = not left
        else:
            ret += intervalSize
        if node >= leftLeaf + intervalSize/2:
            leftLeaf += intervalSize/2
        intervalSize /= 2
    print ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()