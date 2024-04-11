n, l, r = map(int, raw_input().split())
print 2 ** l - 1 + n - l, 2 ** r - 1 + (2 ** (r - 1)) * (n - r)