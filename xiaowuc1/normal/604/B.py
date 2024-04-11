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

def count(l, k):
    ret = 0
    curr = 0
    num = 0
    i = 0
    j = len(l)-1
    while i <= j:
        ret += 1
        if i < j and l[i] + l[j] <= k:
            i += 1
            j -= 1
        else:
            i += 1
    return ret

def solve():
    n, k = read_ints()
    l = read_int_list()[::-1]
    left = l[0]
    right = 2 * left
    while left != right:
        mid = (left + right)/2
        if count(l, mid) <= k:
            right = mid
        else:
            left = mid+1
    print left

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()