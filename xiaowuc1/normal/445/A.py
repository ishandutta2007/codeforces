r, c = (int(x) for x in raw_input().split())
for i in xrange(r):
    s = raw_input()
    ret = ""
    for j in xrange(c):
        if s[j] == '-':
            ret += '-'
        else:
            ret += "WB"[(i+j)%2]
    print ret