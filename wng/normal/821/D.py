n,m,k=[int(i) for i in raw_input().split(" ")]
t={}
nbg=0
dbg={}
rg={}
rrg={}

#for i in range(len(t)):
#    t[i]=[0]*(m+2)


def neighbourslit(r,c):
    res=[]
    for ii in [(r-1,c),(r+1,c),(r,c-1),(r,c+1)]:
        if ii in t:
            res+=[[ii[0],ii[1],rg[t[ii[0],ii[1]]]]]
    return res

for i in range(k):
    r,c=[int(j) for j in raw_input().split(" ")]
    nbs=neighbourslit(r,c)
    if len(nbs)==0:
        nbg+=1
        t[r,c]=nbg
        dbg[nbg]=[(r,c)]
        rg[nbg]=nbg
        rrg[nbg]=[nbg]
    else:
        myg=nbs[0][2]
        t[r,c]=myg
        dbg[myg]+=[(r,c)]
        for j in range(1,len(nbs)):
            oldg=rg[t[nbs[j][0],nbs[j][1]]]
            if myg!=oldg:
                rrg[myg]+=rrg[oldg]
                for g in rrg[oldg]:
                    rg[g]=myg
                del rrg[oldg]
                dbg[myg]+=dbg[oldg]
                del dbg[oldg]
                
#print "nb groupes : {} pour {} lampes".format(len(dbg),k)

#maxandmincolsofgroups
mrc={}
dr={}
dc={}
for gm in dbg.keys():
    minr=n+1
    maxr=0
    minc=m+1
    maxc=0
    for i in dbg[gm]:
        r=i[0]
        c=i[1]
        minr=min(minr,r)
        maxr=max(maxr,r)
        minc=min(minc,c)
        maxc=max(maxc,c)
    mrc[gm]=[minr,maxr,minc,maxc]
    for j in range(minr,maxr+1):
        if j not in dr:
            dr[j]=[]
        dr[j]+=[gm]
    for j in range(minc,maxc+1):
        if j not in dc:
            dc[j]=[]
        dc[j]+=[gm]

dt={}

        
    

def touch(a,b):
    am=min(a,b)
    b=a+b-am
    a=am
    if (a,b) in dt:
        return dt[a,b]
    else:
        dt[a,b]=((mrc[a][2]<=mrc[b][3]+2) and (mrc[b][2]<=mrc[a][3]+2)) or ((mrc[a][0]<=mrc[b][1]+2) and (mrc[b][0]<=mrc[a][1]+2))
        return dt[a,b]

toreach=rg[t[1,1]]
resg={}
toassign=dict(zip(dbg.keys(),[0]*len(dbg)))

def listgroupsinroworcols(rows="All",cols="All"):
    lights=[]
    for i in range(rows[0],rows[1]+1):
        if i in dr:
            lights+=dr[i]
    for i in range(cols[0],cols[1]+1):
        if i in dc:
            lights+=dc[i]
    return list(set(lights))            
#    if rows!="All":
#        lights+=[i for i in t.keys() if i[0] in range(rows[0],rows[1]+1)]
#    if cols!="All":
#        lights+=[i for i in t.keys() if i[1] in range(cols[0],cols[1]+1)]
#    dr={}
#    for g in lights:
#        gg=rg[t[g]]
#        if gg not in dr:
#            dr[gg]=0
#    return dr.keys()

minpay=None
if (n,m) in  t:
    gg=rg[t[n,m]]
    resg[gg]=0
    minpay=0
else:
    for i in range(n):
        if (i,m) in t:
            resg[rg[t[i,m]]]=1
            minpay=1
        if (i,m-1) in t:
            resg[rg[t[i,m-1]]]=1
            minpay=1
    for i in range(m):
        if (n,i) in t:
            resg[rg[t[n,i]]]=1
            minpay=1
        if (n-1,i) in t:
            resg[rg[t[n-1,i]]]=1
            minpay=1


nr=resg.keys()
for i in resg.keys():
    del toassign[i]
while toreach not in resg and len(nr)>0:
    nnr=[]
    for gm in nr:
#        for i in toassign.keys():
#            if touch(gm,i):
#                nnr+=[i]
#                resg[i]=resg[gm]+1
#                del toassign[i]
        ng=listgroupsinroworcols((mrc[gm][0]-2,mrc[gm][1]+2),(mrc[gm][2]-2,mrc[gm][3]+2))
        nng=[i for i in ng if i in toassign]
        nnr+=nng
        for i in nng:
            nnr+=[i]
            resg[i]=resg[gm]+1
            del toassign[i]
    nr=nnr
    
if toreach not in resg:
    print -1
else:
    print resg[toreach]
#print res