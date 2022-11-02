def dfs(x):
    if u[x]:return
    u[x]=1
    for i in e[x]:dfs(i)
R=lambda:map(int,raw_input().split())
T=lambda:[[] for i in range(n+m)]
n,m=R()
e,ans,u=T(),-1,[0]*(n+m)
for i in range(n):
    e[i]=map(lambda x:x+n-1,R())[1:]
    for j in e[i]:e[j]+=[i]
if (e==T()):ans+=1
for i in range(n):
    if (not u[i]):
        ans+=1
        dfs(i)
print ans