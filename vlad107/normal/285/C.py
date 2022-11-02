n=int(input())
a=sorted(map(int,raw_input().split()))
print sum([abs(a[i]-i-1) for i in xrange(n)])