def sec(tup):
    return -tup[1]
def do(graph,top,level):
    if level==0:
        print("!",top)
        return None
    curr=top
    for i in range(level):
        curr=graph[curr]
    print("d",curr)
    dist=int(input())
    if dist==0:
        print("!",curr)
        return None
    newt=top
    for i in range(level-dist//2):
        newt=graph[newt]
    print("s",newt)
    v=int(input())
    newt=v
    newl=dist//2-1
    do(graph,newt,newl)
    return None
def main():
    n=int(input())
    graph=[[] for i in range(n+1)]
    for i in range(n-1):
        u,v=map(int,input().split())
        graph[u].append(v)
        graph[v].append(u)
    print("d",1)
    d=int(input())
    layers=[[1]]
    layer=[1]
    lays=[None]*(n+1)
    lays[1]=0
    for i in range(d):
        newlayer=[]
        for guy in layer:
            for neigh in graph[guy]:
                graph[neigh].remove(guy)
                newlayer.append(neigh)
                lays[neigh]=i+1
        layers.append(newlayer)
        layer=newlayer
    des=[0]*(n+1)
    for guy in layers[-1]:
        des[guy]=1
    for i in range(d):
        for guy in layers[-i-2]:
            des[guy]=sum(des[boi] for boi in graph[guy])
    for guy in range(1,n+1):
        for i in range(len(graph[guy])):
            graph[guy][i]=(graph[guy][i],des[graph[guy][i]])
        graph[guy].sort(key=sec)
    best=[0]*(n+1)
    for i in range(1,n+1):
        if len(graph[i])>0:
            best[i]=graph[i][0][0]
    do(best,1,d)
main()