import sys

n = int(raw_input())

idx = 0
while idx <= 600:
    a = 0
    b = idx
    can = False
    while not can and a <= b:
        can = (n == (12**a + 12**b))
        a += 1
        b -= 1
    if can:
        print "YES"
        print 1
        print idx+1
        l = []
        a = 0
        b = idx
        while a <= b:
            cand = 12**a + 12**b
            if n != cand:
                l.append(cand)
            a += 1
            b -= 1
        l = sorted(l)
        print len(l)
        print "\n".join([str(x) for x in l])
        sys.exit(0)
    idx += 1
print "NO"