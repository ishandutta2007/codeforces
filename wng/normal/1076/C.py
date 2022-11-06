n=int(raw_input())
import math
for i in range(n):
    s=int(raw_input())
    d=s*(s-4)
    if d>=0:
        s1=(s+math.sqrt(d))/2.
        s2=(s-math.sqrt(d))/2.
        print "Y {:.10f} {:.10f}".format(s1,s2)
    else:
        print "N"