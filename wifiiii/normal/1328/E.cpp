#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 200005;
vector<int> g[maxn];
int n;
int fa[maxn][23],dep[maxn];
void dfs(int u)
{
    for(int v:g[u])
    {
        if(fa[u][0]==v) continue;
        dep[v] = dep[u] + 1;
        fa[v][0]=u;
        for(int i=1;1<<i<=dep[v];++i)
            fa[v][i]=fa[fa[v][i-1]][i-1];
        dfs(v);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int d=dep[x]-dep[y],i=0;d;d>>=1,++i)
        if(d&1) x=fa[x][i];
    if(x==y) return x;
    int lg=0;
    for(;(1<<(lg+1))<n;++lg);
    for(int i=lg;i>=0;--i)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int q[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    while(m--)
    {
        int k;
        cin>>k;
        for(int i=1;i<=k;++i)
        {
            cin>>q[i];
            if(q[i] != 1) q[i] = fa[q[i]][0];
        }
        sort(q+1,q+1+k,[&](int i,int j){return dep[i]<dep[j];});
        int ok = 1;
        for(int i=1;i<k;++i)
        {
            if(q[i] == q[i+1]) continue;
            if(dep[q[i]] < dep[q[i+1]] && lca(q[i],q[i+1]) == q[i]) ok = 1;
            else {ok = 0; break;}
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}