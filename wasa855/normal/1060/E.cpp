#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Edge
{
    int to;
    int nxt;
};
Edge edge[400005];
int first[200005];
long long son[200005];
int used[200005];
int ss;
void add(int u,int v)
{
    ss++;
    edge[ss].to=v;
    edge[ss].nxt=first[u];
    first[u]=ss;
}
int cnt;
void dfs(int now,int dep)
{
    used[now]=true;
    if(dep%2==1)
    {
        cnt++;
    }
    son[now]=1;
    for(int i=first[now];i!=0;i=edge[i].nxt)
    {
        int to=edge[i].to;
        if(used[to]==false)
        {
            dfs(to,dep+1);
            son[now]+=son[to];
        }
    }
}
signed main()
{
    int n;
    cin>>n;
    int u,v;
    for(int i=2;i<=n;i++)
    {
        scanf("%d %d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,1);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(son[i])*(n-son[i]);
    }
    cout<<(ans+cnt*(n-cnt))/2<<endl;
    return 0;
}