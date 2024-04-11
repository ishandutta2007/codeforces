#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
#define scsz(s,a,b) int jjj=1;for(int iii=a;iii<=b;++iii) {cout<<s[iii];if(jjj++ % 10) cout<<"\t";else cout<<"\n";}cout<<endl;
const ll mod = 1e9+7;

int vis[200005],c[200005],fa[200005];
vector<int> g[200005];
vector<int> ans;
int flag;
void init(int u)
{
    vis[u] = 1;
    for(int v:g[u])
    {
        if(vis[v]) continue;
        fa[v] = u;
        init(v);
    }
}
void f(int u)
{
    ans.pb(u);c[u]=-c[u];
    if(g[u].size()==1&&u!=1) return;
    for(int v:g[u])
    {
        if(fa[u]==v) continue;
        f(v);
        if(c[v]==-1)
        {
            ans.pb(u);ans.pb(v);ans.pb(u);
            c[v] = 1;
        }
        else
        {
            ans.pb(u);
            c[u] = -c[u];
        }
    }
}
void work(int u)
{
    ans.pb(u);
    for(int v:g[u])
    {
        f(v); //fvvv1v
        if(c[v]==-1)
        {
            ans.pb(u);ans.pb(v);ans.pb(u);
            c[v] = 1;
        }
        else
        {
            ans.pb(u);
            c[u] = -c[u];
        }
    }
    if(c[u]==-1) flag=1;
}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>c[i];
    for(int i=1;i<=n-1;++i)
    {
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
    }
    init(1);
    work(1);
    if(flag)
    {
       ans.pb(g[1][0]);
       ans.pb(1);
       ans.pb(g[1][0]);
       c[1] = -c[1];
    }
    for(int i:ans) cout<<i<<" ";
}