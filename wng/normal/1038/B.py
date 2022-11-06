n=[int(k) for k in raw_input().split(" ")][0]

if n<=2:
    print "No"
else:
    print "Yes"
    print 1,n
    print n-1," ".join([str(k) for k in range(1,n)])