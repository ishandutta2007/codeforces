n, k = (int(x) for x in raw_input().split())
l = [int(x) for x in raw_input().split()]
ret = -1
have = 0
for i in xrange(n):
    have += l[i]
    take = min(have, 8)
    k -= take
    have -= take
    if k <= 0:
        ret = i+1
        break
print ret