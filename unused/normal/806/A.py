def gcd(a, b):
    return b and gcd(b, a % b) or a

t = input()
for i in xrange(t):
    x, y, p, q = map(int, raw_input().split())
    if p == q and x < y:
        print -1
        continue
    if p == 0 and x > 0:
        print -1
        continue

    if p == 0 and x == 0:
        print 0
        continue

    lo = 1
    hi = int(1e30)

    ans = -1

    while lo <= hi:
        mid = (lo + hi) / 2
        X = mid * p * q
        a = X / q - x
        b = X / p - y
        if a >= 0 and b >= 0 and a <= b:
            ans = b
            hi = mid - 1
        else:
            lo = mid + 1

    print ans