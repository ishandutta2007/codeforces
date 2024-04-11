n,m,k = map(int,input().split())
if k==0 or k==n:
    print(-1)
else:
    has = [[] for i in range(n)]
    edge = []
    for i in range(m):
        a,b,c = map(int,input().split())
        edge.append([a-1,b-1,c])
    bad = [False]*n
    bads = map(int,input().split())
    for i in bads:
        bad[i-1] = True
    ans = 10**18
    for e in edge:
        if bad[e[0]]!=bad[e[1]]:
            ans = min(ans,e[2])
    print(ans if ans<10**18 else -1)