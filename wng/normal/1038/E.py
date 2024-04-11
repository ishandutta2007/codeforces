n=[int(k) for k in raw_input().split(" ")][0]

ds=[]
p=range(5) #for scc
nbe=[0]*5


def findp(x):
    global p
    if p[x]!=x:
        p[x]=findp(p[x])
    return p[x]

def merge(x,y):
    global p
    p[findp(x)]=p[findp(y)]
    
sumv=[0]*5
minv=10**6

for i in range(n):
    c1,v,c2=[int(k) for k in raw_input().split(" ")]
    ds+=[(v,c1,c2)]
    if c1!=c2 and findp(c1)!=findp(c2):
        merge(c1,c2)
    sumv[c1]+=v
    sumv[c2]+=v
    nbe[c1]+=1
    nbe[c2]+=1
    if c1!=c2:
        minv=min(minv,v)

ps=[findp(x) for x in range(5)]
maxres=0

for i in range(1,5):
    if i in ps:
        es=[]
        res=0
        for j in range(1,5):
            if ps[j]==i:
                es+=[nbe[j]]
                res+=sumv[j]
        if len([k for k in es if k%2])<4:
            maxres=max(maxres,res)
        else:
            dds=[k for k in ds if k[1]!=k[2] and ps[k[1]]==i and ps[k[2]]==i]
            dds=sorted(dds,key=lambda x:x[0])
            isok=False
            rr=0
            for ik in range(len(dds)):
                k=dds[ik]
                p=range(5)
                for ij in range(len(dds)):
                    j=dds[ij]
                    if ij!=ik:
                        merge(j[1],j[2])
                pps=[findp(x) for x in range(5)]
                if not len([kk for kk in pps[1:] if kk!=pps[1]]):
                    res-=2*k[0]
                    isok=True
                    break
                else:
                    dr={}
                    for kk in range(1,5):
                        if pps[kk] not in dr:
                            dr[pps[kk]]=0
                        dr[pps[kk]]+=sumv[kk]
                    rr=max(rr,max(dr.values())-k[0])
            if isok:
                maxres=max(maxres,max(res,rr))
            else:
                maxres=max(maxres,rr)

print maxres/2