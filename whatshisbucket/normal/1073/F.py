n=int(input())
degs=[0]*n
neighbors=[0]*n
children=[0]*n
useless=[0]*n
for i in range(n):
    neighbors[i]=[]
    children[i]=[]
for i in range(n-1):
    a,b=map(int,input().split())
    degs[a-1]+=1
    degs[b-1]+=1
    neighbors[a-1].append(b-1)
    neighbors[b-1].append(a-1)
for guy in range(n):
    if degs[guy]==1:
        useless[guy]+=1
        newguy=neighbors[guy][0]
        oldguy=guy
        depth=0
        while degs[newguy]==2:
            depth+=1
            useless[newguy]+=1
            if neighbors[newguy][0]==oldguy:
                oldguy=newguy
                newguy=neighbors[newguy][1]
            else:
                oldguy=newguy
                newguy=neighbors[newguy][0]
        children[newguy].append((depth,guy))
for guy in range(n):
    children[guy].sort(reverse=True)
newgraph={}
for i in range(n):
    if useless[i]==0:
        newgraph[i]=[]
for guy in newgraph:
    for guy1 in neighbors[guy]:
        if guy1 in newgraph:
            newgraph[guy].append(guy1)
dfs1={}
currlayer=[(list(newgraph)[0],None)]
currlevel=0
while len(currlayer)>0:
    for guy in currlayer:
        dfs1[guy[0]]=currlevel
    newlayer=[]
    for guy in currlayer:
        for vert in newgraph[guy[0]]:
            if vert!=guy[1]:
                newlayer.append((vert,guy[0]))
    currlayer=newlayer
    currlevel+=1
maxi=0
for guy in dfs1:
    maxi=max(maxi,dfs1[guy])
bestdist=0
bestvert=None
for guy in dfs1:
    if dfs1[guy]==maxi:
        score=children[guy][0][0]+children[guy][1][0]
        if score>=bestdist:
            bestdist=score
            bestvert=guy
dfs2={}
currlayer=[(bestvert,None)]
currlevel=0
while len(currlayer)>0:
    for guy in currlayer:
        dfs2[guy[0]]=currlevel
    newlayer=[]
    for guy in currlayer:
        for vert in newgraph[guy[0]]:
            if vert!=guy[1]:
                newlayer.append((vert,guy[0]))
    currlayer=newlayer
    currlevel+=1
maxi=0
for guy in dfs2:
    maxi=max(maxi,dfs2[guy])
bestdist=0
bestvert1=None
for guy in dfs2:
    if dfs2[guy]==maxi:
        score=children[guy][0][0]+children[guy][1][0]
        if score>=bestdist:
            bestdist=score
            bestvert1=guy
print(children[bestvert][0][1]+1,children[bestvert1][0][1]+1)
print(children[bestvert][1][1]+1,children[bestvert1][1][1]+1)