import heapq
n,m,a,b=map(int,input().split())
graph={i:[] for i in range(n)}
for i in range(m):
    u,v,w=map(int,input().split())
    graph[u-1].append((v-1,w))
    graph[v-1].append((u-1,w))
components=[-1]*n
comp=-1
for i in range(n):
    if components[i]==-1:
        comp+=1
        components[i]=comp
        prev=[]
        layer=[i]
        while layer!=[]:
            newlayer=[]
            for guy in layer:
                for guy1 in graph[guy]:
                    if guy1[1]==a and components[guy1[0]]==-1:
                        newlayer.append(guy1[0])
                        components[guy1[0]]=comp
            prev=layer[:]
            layer=newlayer[:]
useless=[]
for guy in graph:
    for neigh in graph[guy]:
        if components[guy]==components[neigh[0]] and neigh[1]==b:
            useless.append((guy,neigh))
for guy in useless:
    graph[guy[0]].remove(guy[1])
counts=[0]*(comp+1)
for i in range(n):
    counts[components[i]]+=1
bad=[]
for i in range(comp+1):
    if counts[i]<=3:
        bad.append(i)
        for j in range(n):
            if components[j]==i:
                components[j]=-1
for guy in bad[::-1]:
    for i in range(n):
        if components[i]>guy:
            components[i]-=1
comp-=len(bad)
comp+=1
dists=[[float("inf") for i in range(2**comp)] for j in range(n)]
dists[0][0]=0
pq=[]
heapq.heappush(pq,[0,0,0])
remaining=n
visited=[0]*n
while len(pq)>0 and remaining>0:
    dist,vert,mask=heapq.heappop(pq)
    if visited[vert]==0:
        visited[vert]=1
        remaining-=1
    for neigh in graph[vert]:
        if neigh[1]==b:
            if components[vert]==components[neigh[0]] and components[vert]!=-1:
                continue
            if components[neigh[0]]!=-1:
                if mask & (2**components[neigh[0]])>0:
                    continue
            if components[vert]!=-1:
                maskn=mask+2**(components[vert])
            else:
                maskn=mask
        else:
            maskn=mask
        if dist+neigh[1]<dists[neigh[0]][maskn]:
            dists[neigh[0]][maskn]=dist+neigh[1]
            heapq.heappush(pq,[dist+neigh[1],neigh[0],maskn])
optimal=[str(min(dists[i])) for i in range(n)]
print(" ".join(optimal))