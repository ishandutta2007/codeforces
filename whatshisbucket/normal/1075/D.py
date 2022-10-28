def add(child,path):
    copy=path[:]
    return(copy+[child])
def dfs(tree,start,end,path):
    if start==end:
        return path
    for child in tree[start]:
        if child in path:
            continue
        else:
            x=dfs(tree,child,end,add(child,path))
            if x!=None:
                return(x)
    return(None)
t=int(input())
for i in range(t):
    n=int(input())
    neighbors={}
    for i in range(1,n+1):
        neighbors[i]=[]
    for i in range(n-1):
        a,b=map(int,input().split())
        neighbors[a].append(b)
        neighbors[b].append(a)
    k1=int(input())
    mine=list(map(int,input().split()))
    k2=int(input())
    his=list(map(int,input().split()))
    print("B",his[0])
    r=int(input())
    if r in mine:
        print("C",r)
        continue
    way=dfs(neighbors,r,mine[0],[r])
    for guy in way:
        if guy in mine:
            x=guy
            print("A",guy)
            break
    s=int(input())
    if s in his:
        print("C",x)
    else:
        print("C",-1)