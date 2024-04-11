#include <bits/stdc++.h>

using namespace std;
const int maxn=(1<<22)+5;
int n;
bool g1[maxn];
int g[maxn];
bool used[maxn];
int tout[maxn];
int timer=0;
void dfs(int x)
{
    used[x]=true;
    ++timer;
    if(g1[x])
    {
        if(!used[g[x]])
        {
            dfs(g[x]);
        }
    }
    for(int j=0;j<22;++j)
    {
        if(x & (1<<j))
        {
            if(!used[x-(1<<j)])
            {
                dfs(x-(1<<j));
            }
        }
    }
    ++timer;
    tout[x]=timer;
}
void dfs2(int x,int c)
{
    used[x]=true;
    tout[x]=c;
    if(g1[x])
    {
        if(!used[g[x]])
        {
            dfs2(g[x],c);
        }
    }
    for(int j=0;j<22;++j)
    {
        if(x & (1<<j))
        {
            if(!used[x-(1<<j)])
            {
                dfs2(x-(1<<j),c);
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;++i) cin>>a[i];
    for(int i=0;i<m;++i)
    {
        g1[a[i]]=true;
        g[a[i]]=((1<<n)-1-a[i]);
    }
    for(int i=0;i<(1<<n);++i)
    {
        if(!used[i])
        {
            dfs(i);
        }
    }
    /*for(int i=0;i<4;++i)
    {
        for(auto v:g[i])
        {
            cout<<i<<" i "<<v<<" v "<<endl;
        }
        cout<<tout[i]<<" tout[i] "<<endl;
    }*/
    for(int i=0;i<(1<<n);++i) used[i]=false;
    pair <int,int> v[m];
    for(int i=0;i<m;++i) v[i]={tout[a[i]],a[i]};
    sort(v,v+m);
    for(int i=0;i<m;++i)
    {
        if(!used[v[i].second])
        dfs2(v[i].second,v[i].second+1);
    }
    for(int i=0;i<=(1<<n);++i) used[i]=false;
    for(int i=0;i<=(1<<n);++i)
    {
        used[tout[i]]=true;
    }
    int c=0;
    for(int i=1;i<=(1<<n);++i)
    {
        if(used[i]) ++c;
    }
    cout<<c;
    return 0;
}