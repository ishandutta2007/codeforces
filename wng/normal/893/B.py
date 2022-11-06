#[int(k) for k in raw_input().split(" ")]
n=int(raw_input())

dn=1
gn=1
dngn=dn*gn
res=1
mxok=1

while dngn<=n:
    dn=dn*2
    gn=gn*2+1
    dngn=gn*dn
    if n%(dngn)==0:
        res=dngn

print res