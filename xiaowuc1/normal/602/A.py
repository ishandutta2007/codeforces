def parse():
    n, b = (int(x) for x in raw_input().split())
    ret = 0
    l = [int(x) for x in raw_input().split()]
    for y in l:
        ret *= b
        ret += y
    return ret

a = parse()
b = parse()
if a < b:
    print '<'
if a == b:
    print '='
if a > b:
    print '>'