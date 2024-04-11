n, q = (int(x) for x in raw_input().split())
s = raw_input()
for _ in xrange(q):
    l, r, c1, c2 = (x for x in raw_input().split())
    l = int(l) - 1
    r = int(r) - 1
    for i in xrange(l, r+1):
        if s[i] == c1:
            s = s[0:i] + c2 + s[i+1:]
print s