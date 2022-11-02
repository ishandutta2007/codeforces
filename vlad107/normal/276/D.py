l,r=map(long,raw_input().split())
res=0
while (1):
    t=1
    for i in range(70):
        if (2**i<=l):t=2**i
        if (2**i>l)&(2**i<=r):res=max(2**(i+1)-1,res)
    if (l==0):break
    l-=t
    r-=t
print res