
dcp={}

n=int(raw_input())#,x=[int(k) for k in raw_input().split(" ")]
for i in range(n-1):
    u,v=[int(k) for k in raw_input().split(" ")]
    a=u
    b=v
    if a not in dcp:
        dcp[a]={}
    dcp[a][b]=0
    if b not in dcp:
        dcp[b]={}
    dcp[b][a]=0

tovisit=[None]*(n+2)
i=0
tot=[0,0,0]
if n>1:
    tovisit[0]=(1,1)
j=1
while tovisit[i] is not None:
    currnode=tovisit[i][0]
    tot[tovisit[i][1]]+=1
    nextindice=-tovisit[i][1]
    for k in dcp[tovisit[i][0]]:
        del dcp[k][currnode]
        tovisit[j]=(k,nextindice)
        j+=1
    i+=1
    

def comptechilds(x,indice):
    global dcpl
    global dcmo
    if indice>0:
        dcpl[x]=1
    else:
        dcmo[x]=1
    for i in dcp[x]:
        if i not in dcpl and i not in dcmo:
            comptechilds(i,-indice)


#    fr=comptechilds(1,1)        
res=tot[1]*tot[-1]-n+1

print res