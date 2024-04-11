x,y,m=map(long,raw_input().split())
if (x>=m)or(y>=m):
    print 0
    exit(0)
if (x<=0)and(y<=0):
    print -1
    exit(0)
if (x<y):x,y=y,x
ans=0
if (y<=0):
    ll,rr=0,10**50
    while (ll<rr-1):
        mid=(ll+rr)/2
        if (y+mid*x>0):
            rr=mid
        else: ll=mid
    if (y+ll*x<=0):ll=rr
    ans+=ll
    y+=x*ll
while (x<m):
    x,y=x+y,x
    ans+=1
print ans