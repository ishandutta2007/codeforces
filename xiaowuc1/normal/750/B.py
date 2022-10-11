n = int(raw_input())
h = 0
ret = "YES"
for _ in xrange(n):
    l = raw_input().split()
    if l[1][0] == 'E' or l[1][0] == 'W':
        if h == 0 or h == 20000:
            ret = "NO"
    elif l[1][0] == 'N':
        h -= int(l[0])
        if h < 0:
            ret = "NO"
    else:
        assert l[1][0] == 'S'
        h += int(l[0])
        if h > 20000:
            ret = "NO"
if h:
    ret = "NO"
print ret