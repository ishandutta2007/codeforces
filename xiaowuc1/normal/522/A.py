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
    dp = dict()
    dp['polycarp'] = 1
    n = read_int()
    ret = 1
    for _ in xrange(n):
        l = read_list()
        a = l[0].lower()
        b = l[2].lower()
        dp[a] = 1 + dp[b]
        ret = max(ret, dp[a])
    print ret

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()