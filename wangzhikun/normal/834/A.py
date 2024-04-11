l = ["^",">","v","<"]
a,b = raw_input().split(' ')
c = int(raw_input())%4
if (l.index(a)-l.index(b)+4)%4 == (c)%4 and (l.index(a)-l.index(b)+4)%4 != (4-c)%4:
    print "ccw"
elif (l.index(a)-l.index(b)+4)%4 == (4-c)%4 and (l.index(a)-l.index(b)+4)%4 != c%4:
    print "cw"
else:
    print "undefined"