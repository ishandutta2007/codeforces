import math
def f(n,k):
    if k==1:
        return (n*(n+1))//2
    a=math.floor(math.log(n,k))
    b=sum(k**i for i in range(a+1))
    c=sum((i+1)*k**i for i in range(a+1))
    if n<b:
        return c-(b-n)*(a+1)
    else:
        return c+(n-b)*(a+2)
n,s=map(int,input().split())
if s==(n*(n+1))//2:
    print("Yes")
    a=[str(i+1) for i in range(n-1)]
    print(" ".join(a))
elif s>(n*(n+1))//2:
    print("No")
elif s<2*n-1:
    print("No")
else:
    mini=1
    maxi=n-1
    curr=1
    while True:
        a,b=f(n,curr),f(n,curr+1)
        if b>s:
            mini=curr+1
            curr=math.ceil((curr+maxi)/2)
        elif a<=s:
            maxi=curr-1
            curr=(curr+mini)//2
        else:
            opt=curr+1
            break
    depths=[0,1]+[0]*(n-1)
    ins=1
    ind=2
    while True:
        a=min(opt**(ind-1),n-ins)
        depths[ind]=a
        ind+=1
        ins+=a
        if ins==n:
            break
    left=s-b
    far=ind-1
    bulk=ind-1
    if depths[bulk]==1:
        bulk-=1
    while left>0:
        if far+1-bulk<=left:
            far+=1
            left-=far-bulk
            depths[far]+=1
            depths[bulk]-=1
            if depths[bulk]==1:
                bulk-=1
        else:
            depths[bulk]-=1
            depths[bulk+left]+=1
            left=0
    verts=[None]*far
    sumi=0
    for i in range(far):
        verts[i]=list(range(sumi+1,sumi+1+depths[i+1]))
        sumi+=depths[i+1]
    out=""
    for i in range(1,far):
        for j in range(len(verts[i])):
            out+=str(verts[i-1][j//opt])+" "
    print("Yes")
    print(out)