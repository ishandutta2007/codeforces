from collections import defaultdict

n, l, r, x = (int(y) for y in raw_input().split())
ll = [int(y) for y in raw_input().split()]
ret = 0
for mask in xrange(2**n):
    diffs = sorted([ll[i] for i in xrange(n) if (mask&(2**i))])
    if sum(diffs) >= l and sum(diffs) <= r and len(diffs) > 1 and diffs[-1] - diffs[0] >= x:
        ret += 1
print ret