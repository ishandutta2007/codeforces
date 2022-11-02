n,m=map(int,raw_input().split())
a=([(m+1)/2]if (m%2==1)else [(m+1)/2,(m+2)/2])+[(m+1)/2-i/2 if (i%2==0)else (m+1)/2+i/2+1-m%2 for i in xrange(2,m+1)]
print '\n'.join([str(a[i%m]) for i in xrange(n)])