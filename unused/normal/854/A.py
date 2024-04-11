n=input()
def gcd(a, b):
    return gcd(b, a % b) if b else a
for i in xrange(n, 0, -1):
    if n - i <= i:
        continue
    if gcd(n - i, i) > 1:
        continue
    print '%d %d' % (i, n - i)
    exit()