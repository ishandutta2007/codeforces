n, k = map(int, raw_input().split())
d = map(int, raw_input().split())
d.sort()
ans = 0
for i in xrange(k):
    ans += d[i]
print ans