n,m=map(int,raw_input().split())
res=0
for x in xrange(1001):
    for y in xrange(1001):
        if (x+y*y==n)&(x*x+y==m):
            res+=1
print res