#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int to;
    int nxt;
};
Edge edge[400005];
int fir[200005];
int a[200005];
int ss;
void add(int u,int v)
{
    ss++;
    edge[ss].to=v;
    edge[ss].nxt=fir[u];
    fir[u]=ss;
    ss++;
    edge[ss].to=u;
    edge[ss].nxt=fir[v];
    fir[v]=ss;
}
int col[200005];
int fail=false;
int vis[200005];
void dfs(int u,int fa,int co)
{
    // printf("%d %d %d\n",u,fa,co);
    if(fail==true)
    {
        return ;
    }
    col[u]=co;
    for(int i=fir[u];i!=0;i=edge[i].nxt)
    {
        int to=edge[i].to;
        if(fa==to)
        {
            continue;
        }
        if(!col[to])
        {
            dfs(to,u,co^1);
        }
        else if(col[u]==col[to])
        {
            fail=true;
            return ;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        add(u,v);
        a[i]=u;
    }
    dfs(1,-1,0);
    if(fail)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d ",col[i]);
    // }
    for(int i=1;i<=m;i++)
    {
        if(col[a[i]]==1)
        {
            cout<<"0";
        }
        else
        {
            cout<<"1";
        }
    }
    return 0;
}