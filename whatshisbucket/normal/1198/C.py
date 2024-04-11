import sys
input=sys.stdin.readline
T=int(input())
for _ in range(T):
    n,m=map(int,input().split())
    edges=[0]*m
    for i in range(m):
        edges[i]=tuple(map(int,input().split()))
    used=set()
    edgess=[]
    check=0
    for i in range(m):
        if (edges[i][0] not in used) and (edges[i][1] not in used):
            edgess.append(i+1)
            used.add(edges[i][0])
            used.add(edges[i][1])
            check+=1
    if check>=n:
        useful=edgess[:n]
        edgess=[str(guy) for guy in useful]
        print("Matching")
        print(" ".join(edgess))
    else:
        indep=[]
        for i in range(1,3*n+1):
            if i not in used:
                indep.append(i)
        useful=indep[:n]
        verts=[str(guy) for guy in useful]
        print("IndSet")
        print(" ".join(verts))