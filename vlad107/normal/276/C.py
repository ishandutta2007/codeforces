R=lambda:map(int,raw_input().split())
n,q=R()
a=sorted(R())
s=[0]*n
for i in xrange(q):
    l,r=R()
    s[l-1]+=1
    if (r<n):s[r]-=1
for i in xrange(1,n):s[i]=s[i-1]+s[i]
s=sorted(s)
print sum(map(lambda x,y:x*y,a,s))