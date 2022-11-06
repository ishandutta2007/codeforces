import sys
s="no"
i=0
while s=="no":
    print i
    sys.stdout.flush()
    s=raw_input()
    i+=1
if s in ("don't touch me","not bad","cool","don't think so","great"):
    print "normal"
else:
    print "grumpy"