from heapq import *
import sys

MOD1 = 1000000007
MOD2 = 1000000123

def addM(a,b):
    return ((a[0]+b[0])%MOD1,(a[1]+b[1])%MOD2)
def mulM(a,b):
    return ((a[0]*b[0])%MOD1,(a[1]*b[1])%MOD2)

def dijk(adj,n,s):
    dist = [10**18]*n
    ways = [(0,0)]*n
    frontier = []
    dist[s] = 0
    ways[s] = (1,1)
    heappush(frontier,(0,s))
    while (len(frontier)>0):
        x = heappop(frontier)
        if x[0]!=dist[x[1]]:
            continue
        x = x[1]
        for (i,l) in adj[x]:
            if dist[x]+l<dist[i]:
                dist[i] = dist[x]+l
                ways[i] = ways[x]
                heappush(frontier,(dist[i],i))
            elif dist[x]+l==dist[i]:
                ways[i] = addM(ways[i],ways[x])
    return (dist,ways)

n,m,s,t = map(int,sys.stdin.readline().split())
s-=1
t-=1
adj = [[] for i in range(n)]
jda = [[] for i in range(n)]
edges = []

for i in range(m):
    a,b,l = map(int,sys.stdin.readline().split())
    a-=1
    b-=1
    adj[a].append((b,l))
    jda[b].append((a,l))
    edges.append((a,b,l))

one = dijk(adj,n,s)
two = dijk(jda,n,t)

for i in edges:
    if one[0][i[0]]+i[2]+two[0][i[1]]==one[0][t] and mulM(one[1][i[0]],two[1][i[1]])==one[1][t]:
        sys.stdout.write("YES\n")
    else:
        x = one[0][t]-1-one[0][i[0]]-two[0][i[1]]
        if x<=0:
            sys.stdout.write("NO\n")
        else:
            sys.stdout.write("CAN "+str(i[2]-x)+"\n")