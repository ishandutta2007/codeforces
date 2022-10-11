from collections import defaultdict

n, k = (int(x) for x in raw_input().split())
l = [int(x) for x in raw_input().split()]
counts = [0] * 10
ret = 0
for x in l:
    ret += x / 10
    counts[x%10] += 1
for _ in xrange(9, 0, -1):
    maxCanDo = k / (10 - _)
    actual = min(maxCanDo, counts[_])
    k -= actual * (10 - _)
    ret += actual
print min(10*n, ret + k/10)