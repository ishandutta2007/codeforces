import sys
sys.setrecursionlimit(300000)
n,m,k=map(int,input().split())
x=list(map(int,input().split()))
edges=[]
for i in range(m):
    a,b,c=map(int,input().split())
    edges.append((c,a,b))
edges.sort()
tree=[i for i in range(n+1)]
used=[]
edgess=0
def q(x):
    if x!=tree[x]:
        tree[x]=q(tree[x])
    return(tree[x])
for w,u,v in edges:
    if edgess==n-1:
        break
    a,b=q(u),q(v)
    if a%2==1:
        a,b=b,a
    if a!=b:
        tree[a]=b
        used.append((w,u,v))
        edgess+=1
neigh=[]
for i in range(n+1):
    neigh.append([])
for w,u,v in used:
    neigh[u].append((v,w))
    neigh[v].append((u,w))
layer=[x[0]]
pars=[None]
dists=[None]*(n+1)
dists[x[0]]=0
while layer!=[]:
    newlayer=[]
    newpars=[]
    for i in range(len(layer)):
        guy=layer[i]
        par=pars[i]
        for v,w in neigh[guy]:
            if v!=par:
                dists[v]=max(dists[guy],w)
                newlayer.append(v)
                newpars.append(guy)
    layer=newlayer
    pars=newpars
high=0
for guy in x:
    high=max(high,dists[guy])
print((str(high)+" ")*k)