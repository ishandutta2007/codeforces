n,m=map(int,raw_input().split())
N=int((10**5)+100)
r,c=[0]*n,[0]*m
a=[0]*2+[1]*N
for i in xrange(2,N): 
    if (a[i]):
        for j in xrange(2,1+(N/i)):a[i*j]=0
for i in reversed(xrange(1,N)):
    if (a[i]):a[i]=i
    else:a[i]=a[i+1]
for i in xrange(n):
    s=map(lambda x:a[x]-x,map(int,raw_input().split()))
    r[i]=sum(s)
    c=map(lambda x,y:x+y,c,s)
print min(min(r),min(c))