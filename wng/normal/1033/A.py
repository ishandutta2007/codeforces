n=[int(k) for k in raw_input().split(" ")][0]
a=[int(k) for k in raw_input().split(" ")]
b=[int(k) for k in raw_input().split(" ")]
c=[int(k) for k in raw_input().split(" ")]

if (a[0]-b[0])*(a[0]-c[0])>0 and (a[1]-b[1])*(a[1]-c[1])>0:
    print "YES"
else:
    print "NO"