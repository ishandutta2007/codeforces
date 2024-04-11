#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <pair<int,int> > g[maxn];
vector <int> u[maxn];
int col[maxn];
bool used[maxn];
int tout[maxn];
void dfs(int x)
{
    used[x]=true;
    for(auto h:g[x])
    {
        int v=h.first;
        if(!used[v])
        {
            col[v]=col[x]^1;dfs(v);
        }
    }
}
int timer=0;
void dfs2(int x)
{
    used[x]=true;
    ++timer;
    for(auto v:u[x])
    {
        if(!used[v])
        {
            dfs2(v);
        }
    }
    ++timer;
    tout[x]=timer;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <vector <int> > b;
    for(int i=0;i<m;++i)
    {
        int typ,x,y;
        cin>>typ>>x>>y;
        --x;--y;
        b.push_back({typ,x,y});
        g[x].push_back({y,typ});g[y].push_back({x,typ});
    }
    for(int i=0;i<n;++i) if(!used[i]) dfs(i);
    for(auto h:b)
    {
        int x=h[1];int y=h[2];int typ=h[0];
        if(col[x]==1) swap(x,y);
        if(typ==1) u[x].push_back(y);
        else u[y].push_back(x);
    }
    for(int i=0;i<n;++i) used[i]=false;
    for(int i=0;i<n;++i) if(!used[i]) dfs2(i);
    for(int i=0;i<n;++i)
    {
        for(auto h:u[i])
        {
            if(col[h]==col[i] || tout[h]>tout[i]) {cout<<"NO";return 0;}
        }
    }
    pair <int,int> ans[n];
    for(int i=0;i<n;++i) {ans[i]={col[i],tout[i]};}
    cout<<"YES"<<'\n';
    for(auto h:ans) cout<<(h.first ? 'L' : 'R')<<' '<<h.second<<'\n';
    return 0;
}