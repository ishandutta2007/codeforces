n=input()
a=map(int,raw_input().split())
print sum([max(0,a[i]-a[i+1]) for i in xrange(n-1)])