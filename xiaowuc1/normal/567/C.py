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
    n, k = read_ints()
    l = read_int_list()
    total = defaultdict(int)
    for x in l:
        total[x] += 1
    seen = defaultdict(int)
    ret = 0
    for x in l:
        if x % k == 0:
            left = seen[x/k]
            right = total[x*k] - seen[x*k]
            if k*x == x:
                right -= 1
            ret += left * right
        seen[x] += 1
    print ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()