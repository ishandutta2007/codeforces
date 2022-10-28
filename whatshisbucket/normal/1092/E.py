import math
n,m=map(int,input().split())
neigh=[]
for i in range(n):
    neigh.append([])
for i in range(m):
    a,b=map(int,input().split())
    neigh[a-1].append(b-1)
    neigh[b-1].append(a-1)
seen=set()
index=[0]*n
diams=[]
trees=0
for i in range(n):
    if i not in seen:
        trees+=1
        index[i]=trees
        seen.add(i)
        layer=[i]
        prev=None
        pars=[None]
        while layer!=[]:
            newlayer=[]
            newpars=[]
            for i in range(len(layer)):
                vert=layer[i]
                par=pars[i]
                for child in neigh[vert]:
                    if child!=par:
                        newlayer.append(child)
                        newpars.append(vert)
                        index[child]=trees
                        seen.add(child)
            prev=layer
            layer=newlayer
            pars=newpars
        far=prev[0]
        layer=[[far]]
        pars=[None]
        prev=None
        while layer!=[]:
            newlayer=[]
            newpars=[]
            for i in range(len(layer)):
                vert=layer[i][-1]
                par=pars[i]
                for child in neigh[vert]:
                    if child!=par:
                        newlayer.append(layer[i]+[child])
                        newpars.append(vert)
            prev=layer
            layer=newlayer
            pars=newpars
        diam=prev[0]
        lent=len(diam)
        mid=diam[lent//2]
        diams.append((lent-1,mid))
diams.sort(reverse=True)
poss=[diams[0][0]]
if len(diams)>1:
    poss.append(math.ceil(diams[0][0]/2)+1+math.ceil(diams[1][0]/2))
if len(diams)>2:
    poss.append(math.ceil(diams[1][0]/2)+2+math.ceil(diams[2][0]/2))
print(max(poss))
cent=diams[0][1]
for i in range(len(diams)-1):
    print(cent+1,diams[i+1][1]+1)