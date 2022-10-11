n, t = (int(x) for x in raw_input().split())
l = [int(x) for x in raw_input().split()]
ret = n
for i in xrange(n):
    t -= max(0, 86400 - l[i])
    if t <= 0:
        ret = i+1
        break
print ret