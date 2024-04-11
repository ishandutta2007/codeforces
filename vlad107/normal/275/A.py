a=[[0]*5]*5
for i in xrange(3):a[i]=map(int,raw_input().split())+[0]*2
for i in xrange(3):print "".join(map(str,map(lambda j:((a[i][j]+a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1])&1)^1,xrange(3))))