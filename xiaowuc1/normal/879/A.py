n = int(raw_input())
ret = 0
for _ in xrange(n):
    s, d = (int(x) for x in raw_input().split())
    while ret < s or (ret-s)%d != 0:
        ret += 1
    if _ != n-1:
        ret += 1
print ret