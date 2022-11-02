R=lambda:map(int,raw_input().split())
n,d=R()
a,j,res=R(),0,0
for i in xrange(n):
    while ((j<n)and(a[j]-a[i]<=d)):j+=1
    res+=max((j-i-1)*(j-i-2)/2,0)
print res