R=lambda:map(int,raw_input().split())
n,m=R()
a=R()
q=[i for i in range(n)]
w=[i for i in range(n)]
for i in reversed(range(n-1)):
    if (a[i]<=a[i+1]):q[i]=q[i+1]
    if (a[i]>=a[i+1]):w[i]=w[i+1]
for i in xrange(m):
    l,r=R()
    if (w[q[l-1]]>=r-1):
        print "Yes"
    else:print "No"