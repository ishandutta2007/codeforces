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
    a, b = read_floats()
    if b > a:
        print -1
        return
    print (a+b)/(2*(int(a+b)/int(2*b)))

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()