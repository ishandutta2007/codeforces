#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int n;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int dep[Maxn],mx1[Maxn],mx2[Maxn],now=0;
int ans1,ans2,ans3,ans4;
pair<int,int> mx;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
    int cnt=0;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            dep[v]=dep[u]+1;
            dfs(v,u);
            if (mx1[u]==0||dep[mx1[v]]>dep[mx1[u]])
            {
                mx2[u]=mx1[u];
                mx1[u]=mx1[v];
            } else if (mx2[u]==0||dep[mx1[v]]>dep[mx2[u]]) mx2[u]=mx1[v];
            ++cnt;
        }
    }
    if (cnt==0) mx1[u]=u;
    else if (cnt>=2)
    {
        if (make_pair(dep[u],dep[mx1[u]]+dep[mx2[u]])>mx)
        {
            mx=make_pair(dep[u],dep[mx1[u]]+dep[mx2[u]]);
            now=u;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
    }
    mx=make_pair(0,0);
    memset(dep,0,sizeof(dep));
    memset(mx1,0,sizeof(mx1));
    memset(mx2,0,sizeof(mx2));
    dfs(1,-1);
    ans1=mx1[now],ans3=mx2[now];
    memset(dep,0,sizeof(dep));
    memset(mx1,0,sizeof(mx1));
    memset(mx2,0,sizeof(mx2));
    mx=make_pair(0,0);
    dfs(now,-1);
    ans2=mx1[now],ans4=mx2[now];
    printf("%d %d\n",ans1,ans2);
    printf("%d %d\n",ans3,ans4);
    return 0;
}