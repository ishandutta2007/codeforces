n,m=map(int,raw_input().split())
if (n+m==0):
    print 0,0
elif n==0:
    print "Impossible"
else:
    print n+m-min(n,m),n+m-min(1,m)