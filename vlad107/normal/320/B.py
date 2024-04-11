def dfs(x):
    if (t[x]!=-1):return t[x]
    t[x]=0
    for i in range(len(s)):
        if ((s[x][0]>s[i][0])and(s[x][0]<s[i][1]))or((s[x][1]>s[i][0])and(s[x][1]<s[i][1])):t[x]=t[x] or dfs(i)
    return t[x]
n=int(input())
s=[]
for i in range(n):
    t,x,y=map(int,raw_input().split())
    if (t==1):
        s+=[[x,y]]
    else:
        t=[-1]*n
        t[y-1]=1
        print ['NO','YES'][dfs(x-1)]