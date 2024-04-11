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

def get_list(d):
    ret = []
    for x in d:
        ret.append((x, d[x]))
    return sorted(ret)

def solve():
    n, s = read_ints()
    buy = defaultdict(int)
    sell = defaultdict(int)
    for _ in xrange(n):
        l = read_list()
        dict_to_use = buy if l[0] == 'B' else sell
        dict_to_use[int(l[1])] += int(l[2])
    buy_list = get_list(buy)[::-1]
    sell_list = get_list(sell)
    ret = []
    for _ in xrange(min(len(sell), s)):
        ret.append("S {} {}".format(sell_list[_][0], sell_list[_][1]))
    ret = ret[::-1]
    for x in ret:
        print x
    for _ in xrange(min(len(buy), s)):
        print "B {} {}".format(buy_list[_][0], buy_list[_][1])


qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()