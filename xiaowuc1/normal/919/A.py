n, m = (int(x) for x in raw_input().split())
ret = 1e99
for _ in xrange(n):
    a, b = (int(x) for x in raw_input().split())
    ret = min(ret, m*a/float(b))
print ret