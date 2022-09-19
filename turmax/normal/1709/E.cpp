#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector<int> a[maxn];bool used[maxn];
int c[maxn];int t[maxn];int tin[maxn];int tout[maxn];int u[maxn][20];int pr[maxn];int timer=0;
set <int> color;int res=0;
void dfs2(int x)
{
    used[x]=true;set<int> cur={c[x]};bool ok=true;
    for(int v:a[x]) {if(!used[v]) {dfs2(v);if(color.size()>cur.size()) cur.swap(color); for(auto h:color) {if(cur.count(h^t[x])) ok=false;} for(auto h:color) {cur.insert(h);} color.clear();}}
    if(ok) {color.swap(cur);}
    else {++res;color.clear();}
    used[x]=false;
}
void dfs(int x)
{
    used[x]=true;tin[x]=timer;++timer;for(int i=1;i<20;++i) u[x][i]=u[u[x][i-1]][i-1];
    for(int v:a[x]) {if(!used[v]) {pr[v]=x;u[v][0]=x;c[v]=c[x]^c[v];dfs(v);}}
    ++timer;tout[x]=timer;used[x]=false;
}
bool pred(int x,int y)
{
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
int lca(int x,int y)
{
    if(pred(x,y)) return x;
    if(pred(pr[x],y)) return pr[x];
    for(int i=1;i<20;++i)
    {
        if(pred(u[x][i],y))
        {
            return lca(u[x][i-1],y);
        }
    }
    assert(false);
}
bool cmp(int x,int y)
{
    return tin[x]<tin[y];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;++n;for(int i=1;i<n;++i) {cin>>c[i];t[i]=c[i];}
    for(int i=0;i<n-2;++i) {int x,y;cin>>x>>y;a[x].push_back(y);a[y].push_back(x);} a[0].push_back(1);a[1].push_back(0);
    dfs(0);
    //for(int i=0;i<n;++i) {u[c[i]].push_back(i);}
    dfs2(0);
    cout<<res;
    return 0;
}