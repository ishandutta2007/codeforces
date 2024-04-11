n=int(input())
a=map(int,raw_input().split())
for i in xrange(min(a[0],a[n-1])+2):
    fail=0
    for j in xrange(n-2):
        if ((a[j]-i<=0)&(a[j+1]-i<=0)):
            fail=1
            break
    if ((a[0]-i<0)|(a[n-1]-i<0)):
        print i-1
        exit(0)
    if (fail==1):
        print i
        exit(0)