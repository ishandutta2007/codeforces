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

def prime(n):
    i = 3
    while i * i <= n:
        if n%i == 0:
            return False
        i += 2
    return True

def solve():
    n = read_int()
    if n < 9:
        print 1
        print n
        return
    ret = []
    a = 3
    while not ret:
        if not prime(a):
            a += 2
            continue
        b = a
        while not ret and b <= n - a - b:
            c = n - a - b
            if prime(b) and prime(c):
                ret.append(str(a))
                ret.append(str(b))
                ret.append(str(c))
            b += 2
    print len(ret)
    print " ".join(ret)

qq = 1
# qq = 2**30
# qq = read_int()
for _________ in xrange(qq):
    solve()