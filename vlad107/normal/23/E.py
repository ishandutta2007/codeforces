def dfs(x,px):
    s[x]=1
    for i in g[x]:
        if (i!=px):s[x]+=deg[i]
    for i in xrange(s[x]+1):f[x]+=[0]
    f[x][0]=1
    f[x][1]=1
    for i in g[x]:
        if (i!=px):
            dfs(i,x)
    for i in xrange(1,s[x]+1):
        if (f[x][i]!=0):
            f[x][0]=max(f[x][0],f[x][i]*i)
    if (px<0): return 0
    for i in reversed(range(s[px]+1)):
        if (f[px][i]!=0):
            for j in reversed(range(min(s[px]+1-i,s[x]+1))):
                if (f[x][j]!=0)and(i+j<=s[px]):
                    f[px][i+j]=max(f[px][i+j],f[px][i]*f[x][j])
R=lambda:map(int,raw_input().split())
n=int(input())
deg=[0]*n
s=[0]*n
g,f=[],[]
for i in xrange(n):
    g+=[[]]
    f+=[[]]
for i in xrange(n-1):
    x,y=R()
    x-=1
    y-=1
    deg[x]+=1
    deg[y]+=1
    g[x]+=[y]
    g[y]+=[x]
dfs(0,-1)
print f[0][0]