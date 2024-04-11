from collections import defaultdict

n = int(raw_input())
l = [int(x) for x in raw_input().split()]
ret = abs(l[0])
for i in xrange(1, n):
    ret += abs(l[i] - l[i-1])
print ret