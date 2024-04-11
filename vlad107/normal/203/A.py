x,t,a,b,da,db=map(int,raw_input().split(' '))
for i in xrange(t):
    for j in xrange(t):
        if ((a-i*da+b-j*db==x)|(a-i*da==x)|(b-j*db==x)|(x==0)):
            print "YES"
            exit(0)
print "NO"