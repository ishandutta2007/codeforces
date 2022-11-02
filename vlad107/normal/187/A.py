n=int(input())
a=map(int,raw_input().split())
b=map(int,raw_input().split())
c=[]
for i in xrange(n):c.append(0)
for i in xrange(n):c[b[i]-1]=i
for i in xrange(n):a[i]=c[a[i]-1]
#print a
ans,j=0,0
for i in xrange(1,n):
    if (a[i]<a[i-1]):
        ans=n-i
        break
print ans