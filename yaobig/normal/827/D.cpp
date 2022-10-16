#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

typedef array<int,3> E;

vi te[maxn+5],nte[maxn+5];
E e[maxn+5];
int id[maxn+5];

int fa[maxn+5];
int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}

int dep[maxn+5];
int anc[19][maxn+5],W[18][maxn+5];

void caldep(int now,int fa)
{
    dep[now]=dep[fa]+1;
    for(auto i: te[now])
    {
        auto [x,y,w]=e[i];
        int v=x^y^now;
        if(v==fa) continue;
        anc[0][v]=now;
        W[0][v]=w;
        caldep(v,now);
    }
}
int swim(int x,int h)
{
    rep(i,0,17) if(h&(1<<i)) x=anc[i][x];
    return x;
}
int pathmax(int x,int h)
{
    int res=0;
    rep(i,0,17) if(h&(1<<i)) chmax(res,W[i][x]),x=anc[i][x];
    return res;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    x=swim(x,dep[x]-dep[y]);
    if(x==y) return x;
    per(i,0,17) if(anc[i][x]!=anc[i][y]) x=anc[i][x],y=anc[i][y];
    return anc[0][x];
}

int ans[maxn+5];
vi pool[maxn+5];
set<pii> *S[maxn+5]; 

int dfs(int now,int fa)
{
    for(auto i: te[now])
    {
        auto [x,y,w]=e[i];
        int v=x^y^now;
        if(v==fa) continue;
        ans[i]=dfs(v,now)-1;
        if(S[now]->size()<S[v]->size()) swap(S[now],S[v]);
        for(auto it: *S[v]) S[now]->insert(it);
        delete(S[v]);
    }
    for(auto i: pool[now]) S[now]->erase({e[i][2],i});
    if(S[now]->size()==0) return 0;
    return S[now]->begin()->FI;
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m) 
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        e[i]={x,y,w};
    }
    rep(i,1,m) id[i]=i;
    sort(id+1,id+m+1,[](int x,int y){return e[x][2]<e[y][2];});
    rep(i,1,n) fa[i]=i;
    rep(i,1,m) 
    {
        auto [x,y,_]=e[id[i]];
        int fx=getfa(x),fy=getfa(y);
        if(fx==fy) nte[x].pb(id[i]),nte[y].pb(id[i]);
        else 
        {
            fa[fy]=fx;
            te[x].pb(id[i]),te[y].pb(id[i]);
        }
    }
    caldep(1,0);
    rep(i,1,17) rep(now,1,n) 
    {
        anc[i][now]=anc[i-1][anc[i-1][now]];
        W[i][now]=max(W[i-1][now],W[i-1][anc[i-1][now]]);
    }
    rep(i,1,m) ans[i]=-2;
    rep(now,1,n) S[now]=new set<pii>;
    rep(now,1,n) for(auto i: nte[now]) if(ans[i]==-2)
    {
        auto [x,y,w]=e[i];
        int l=lca(x,y);
        ans[i]=max(pathmax(x,dep[x]-dep[l]),pathmax(y,dep[y]-dep[l]))-1;
        S[x]->insert({w,i});
        S[y]->insert({w,i});
        pool[l].pb(i);
    }
    dfs(1,0);
    rep(i,1,m) printf("%d%c",ans[i]," \n"[i==m]);
    return 0;
}