#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

const int maxn = 100005;
vector<int> g[maxn];
int low[maxn],dfn[maxn],dfscnt=0;
int st[maxn],ins[maxn],tp=0;
int scc[maxn],sccno=0;
void tarjan(int u)
{
    low[u]=dfn[u]=++dfscnt;
    st[++tp]=u,ins[u]=1;
    for(int v:g[u])
    {
        if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        ++sccno;
        int p=-1;
        while(p!=u) p=st[tp--],ins[p]=0,scc[p]=sccno;
    }
}
pair<int,int> es[maxn];
int deg[maxn], par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    par[x]=y;
}
int main() {
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        es[i]={u,v};
    }
    for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
//    for(int i=1;i<=sccno;++i) par[i]=i;
    for(int i=1;i<=m;++i) {
        int u=es[i].first,v=es[i].second;
        if(scc[u]==scc[v]) continue;
        deg[scc[v]]++;
//        par[find(scc[v])]=find(scc[u]);
    }
    int cnt=0;
    for(int i=1;i<=sccno;++i) if(scc[s] != i && deg[i] == 0) ++cnt;
    cout << cnt << endl;
}