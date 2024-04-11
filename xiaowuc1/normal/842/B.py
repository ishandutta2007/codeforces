from math import sqrt

r, d = (int(x) for x in raw_input().split())

low = (r-d)
high = r

n = int(raw_input())
ret = 0
for _ in xrange(n):
    xx, yy, rr = (int(x) for x in raw_input().split())
    dist = sqrt(xx*xx + yy*yy)
    if dist - rr >= low-1e-9 and dist + rr <= high+1e-9:
        ret += 1
print ret