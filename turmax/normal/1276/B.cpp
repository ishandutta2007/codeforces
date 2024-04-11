#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > a;
vector <bool> used1;
vector <bool> used2;
int u,v;
void dfs1(int x)
{
    used1[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        if(!used1[a[x][i]])
        {
            dfs1(a[x][i]);
        }
    }
}
void dfs2(int x)
{
    used2[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        if(!used2[a[x][i]])
        {
            dfs2(a[x][i]);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    for(int cycle=0;cycle<q;++cycle)
    {
    int n,m;
    int x,y;
    cin>>n>>m>>u>>v;
    u--;
    v--;
    a.resize(n);
    used1.resize(n);
    used2.resize(n);
    for(int i=0;i<n;++i)
    {
        a[i].clear();
        used1[i]=false;
        used2[i]=false;
    }
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int sum1=0,sum2=0;
    used1[v]=true;
    dfs1(u);
    used2[u]=true;
    dfs2(v);
    for(int i=0;i<n;++i)
    {
        if(!used1[i])
        {
            ++sum1;
        }
        if(!used2[i])
        {
            ++sum2;
        }
    }
    cout<<sum1*sum2<<endl;
    }
    return 0;
}