n,x,k=[int(k) for k in raw_input().split(" ")]
a=[int(kk) for kk in raw_input().split(" ")]

sa=sorted(a)

en=0
mst=0
res=0
for st in range(n):
    #we want end between
    s=sa[st]
    fend=(((s-1)/x+1)*x +(k-1)*x)
    lend=fend+x
    while mst<n and sa[mst]<max(s,fend):
        mst+=1
    while en<n and sa[en]<lend:
        en+=1
    res+=en-mst
   # print st,sa[st],en,mst,(en-max(st+1,mst))*2+(1 if en>st else 0)

print res