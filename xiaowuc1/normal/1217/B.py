def solve():
    n, k = (int(x) for x in raw_input().split())
    maxInc = 0
    maxBlow = 0
    for _ in xrange(n):
        d, h = (int(x) for x in raw_input().split())
        maxBlow = max(maxBlow, d)
        maxInc = max(maxInc, d-h)
    if maxBlow >= k:
        print 1
    elif maxInc <= 0:
        print -1
    else:
        print (k-maxBlow+maxInc-1)/maxInc+1

t = int(raw_input())
for _ in xrange(t):
    solve()