n=int(input())
graph=[{},{},{}]
for i in range(n):
    for j in range(n):
        graph[0][(i,j)]=[(k,j) for k in range(n)]+[(i,k) for k in range(n)]
        graph[0][(i,j)].remove((i,j))
        graph[0][(i,j)].remove((i,j))
        graph[1][(i,j)]=[]
        for k in range(n):
            for l in range(n):
                if abs(k-i)==abs(l-j)!=0:
                    graph[1][(i,j)].append((k,l))
        graph[2][(i,j)]=[]
        for k in range(n):
            for l in range(n):
                if {abs(k-i),abs(l-j)}=={1,2}:
                    graph[2][(i,j)].append((k,l))      

dists=[[{},{},{}],[{},{},{}],[{},{},{}]]
for i in range(n):
    for j in range(n):
        for k in range(3):
            dists[k][k][(i,j,i,j)]=0
for i in range(n):
    for j in range(n):
        for k in range(3):
            layers=[[(i,j,k,0)],[],[],[],[]]
            for l in range(4):
                for guy in layers[l]:
                    for m in range(3):
                        if m!=guy[2]:
                            if (i,j,guy[0],guy[1]) not in dists[k][m]:
                                layers[l+1].append((guy[0],guy[1],m,guy[3]+1))
                                dists[k][m][(i,j,guy[0],guy[1])]=1000*(l+1)+guy[3]+1
                    for boi in graph[guy[2]][(guy[0],guy[1])]:
                        if (i,j,boi[0],boi[1]) not in dists[k][guy[2]]:
                            layers[l+1].append((boi[0],boi[1],guy[2],guy[3]))
                            dists[k][guy[2]][(i,j,boi[0],boi[1])]=1000*(l+1)+guy[3]
                        elif 1000*(l+1)+guy[3]<dists[k][guy[2]][(i,j,boi[0],boi[1])]:
                            layers[l+1].append((boi[0],boi[1],guy[2],guy[3]))
                            dists[k][guy[2]][(i,j,boi[0],boi[1])]=1000*(l+1)+guy[3]
locs=[None]*(n**2)
for i in range(n):
    a=list(map(int,input().split()))
    for j in range(n):
        locs[a[j]-1]=(i,j)
best=(0,0,0)
for i in range(n**2-1):
    tup=(locs[i][0],locs[i][1],locs[i+1][0],locs[i+1][1])
    new0=min(best[0]+dists[0][0][tup],best[1]+dists[1][0][tup],best[2]+dists[2][0][tup])
    new1=min(best[0]+dists[0][1][tup],best[1]+dists[1][1][tup],best[2]+dists[2][1][tup])
    new2=min(best[0]+dists[0][2][tup],best[1]+dists[1][2][tup],best[2]+dists[2][2][tup])
    best=(new0,new1,new2)
a=min(best)
print(a//1000,a%1000)