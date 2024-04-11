#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=1e5+5;
const int M=(1<<22)+5;
const int K2=13;
const int mod=998244353;
int read(){int x=0;char ch=getchar();while(ch>'9'||ch<'0'){ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
set<int> T[N];
int n,k,tot;
int dep[N],sz[N],mxsz[N],Fa[N];
vector<pii> ans;
int G,mx,mn;
bool vis[N];
void getG(int u,int fa)//
{
    sz[u]=1,mxsz[u]=0;
    for (int v:T[u]) if (v!=fa) getG(v,u),sz[u]+=sz[v],mxsz[u]=max(mxsz[u],sz[v]);
    mxsz[u]=max(mxsz[u],n-sz[u]);
    if (mxsz[u]<mxsz[G]) G=u;
}
void DFS(int u,int fa){Fa[u]=fa;sz[u]=1;dep[u]=dep[fa]+1;for (int v:T[u]) if (v!=fa) DFS(v,u),sz[u]+=sz[v];}// dfs  siz  dep
int now;
struct subtree{int id;bool operator<(const subtree &o)const{return sz[id]<sz[o.id];}};// G 
priority_queue<subtree> Q;
struct lca{int x;bool operator<(const lca &o)const{return dep[x]==dep[o.x]?x<o.x:dep[x]<dep[o.x];}};// lca  set  multiset erase 
set<lca> S[N];
void del(int u,int v){T[u].erase(v);T[v].erase(u);}//
vector<int> A[N];
int la1,la2;
void getlca(int u,int id)
{
    // lca   
    int cnt=0;
    for (int v:T[u]) if (v!=Fa[u]) getlca(v,id),cnt++;
    if (cnt) S[id].insert({u});
}
void dfs(int u,int id)
{
    //
    if (u!=la1 && u!=la2) A[id].push_back(u);
    for (int v:T[u]) if (v!=Fa[u]) dfs(v,id);
}
void merge(int i,int j)
{
    // i  j 
    int x=A[i].back(),y=A[j].back();
    ans.push_back({x,y});
    A[i].pop_back();A[j].pop_back();
    sz[i]--;sz[j]--;if (sz[i]) Q.push({i});if (sz[j]) Q.push({j});
}
void DOIT()
{
    //
    // siz 
    for (int v:T[G]) dfs(v,v);
    while (Q.size()>=2)
    {
        int i=Q.top().id;Q.pop();
        int j=Q.top().id;Q.pop();
        merge(i,j);
    }
    ans.push_back({G,A[Q.top().id].back()});
    puts("YES");
    for (pii p:ans) cout<<p.fi<<" "<<p.se<<"\n";
    exit(0);
}
void solve()
{
    int t=Q.top().id;Q.pop();
    if (sz[t]==1) DOIT();// RE
    sz[t]-=2;
    int u=(*S[t].rbegin()).x;
    if (now-2*dep[u]<=k)
    {
        if (now==k) {sz[t]+=2;Q.push({t});DOIT();}
        int d=(now-k)/2;//
        vector<int> son;
        for (int v:T[u]) if (v!=Fa[u]) {son.push_back(v);if (son.size()==1) break;}
        //
        while (dep[u]>d) u=Fa[u];
        ans.push_back({u,son[0]});
        la1=u;la2=son[0];if (sz[t]) Q.push({t});
        DOIT();
    } else 
    {
        now-=2*dep[u];
        vector<int> son;
        for (int v:T[u]) if (v!=Fa[u]){son.push_back(v);if (son.size()==2) break;}
        if (son.size()==1)
        {
            // 1 
            ans.push_back({u,son[0]});
            del(u,son[0]);del(Fa[u],u);
            S[t].erase({u});
            if (T[Fa[u]].size()==1) S[t].erase({Fa[u]});
        } else 
        {
            // 2  2 
            ans.push_back({son[0],son[1]});
            del(u,son[0]);del(u,son[1]);
            if (T[u].size()==1) S[t].erase({u});
        }

    }
    if (sz[t]) Q.push({t});// push 
}
signed main()
{
    rd(n);rd(k);
    for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].insert(y),T[y].insert(x);
    mxsz[0]=n;getG(1,0);for (int i=1;i<=n;i++) sz[i]=0;
    dep[0]=-1;DFS(G,0);
    for (int i=1;i<=n;i++) if (i!=G) mn+=sz[i]%2,mx+=sz[i];
    if (k<mn || k>mx || (k+mn)%2==1) {puts("NO");return 0;}
    for (int v:T[G]) getlca(v,v);for (int v:T[G]) Q.push({v});
    now=mx;while (1) solve();
}