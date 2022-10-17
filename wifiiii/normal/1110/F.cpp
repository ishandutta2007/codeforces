#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
#define int ll
struct edge {
    int v,w;
    bool operator < (const edge & e) const
    {
        return v<e.v;
    }
};
const int maxn = 500005;
struct qry {
    int l,r,id;
};
vector<edge> g[maxn];
vector<qry> qr[maxn];
ll dis[maxn];
int id[maxn],sz[maxn],rid[maxn],tot=0;
void dfs(int u)
{
    ++tot;id[u]=tot;rid[tot]=u;sz[u]=1;
    for(edge e:g[u])
    {
        dis[e.v]=dis[u]+e.w;
        dfs(e.v);
        sz[u]+=sz[e.v];
    }
}
ll mx[maxn<<2],lz[maxn<<2];
void build(int l,int r,int rt)
{
    if(l==r)
    {
        if(sz[rid[l]] == 1) mx[rt]=dis[rid[l]];
        else mx[rt]=1e17;
        return;
    }
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    mx[rt]=min(mx[rt<<1],mx[rt<<1|1]);
}
void update(int L,int R,ll val,int l,int r,int rt)
{
    if(L<=l && r<=R) {lz[rt]+=val,mx[rt]+=val;return;}
    int m = (l+r)/2;
    if(lz[rt])
    {
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt];
        mx[rt<<1]+=lz[rt],mx[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    if(m>=L) update(L,R,val,l,m,rt<<1);
    if(m< R) update(L,R,val,m+1,r,rt<<1|1);
    mx[rt]=min(mx[rt<<1],mx[rt<<1|1]);
}
ll query(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R) return mx[rt];
    ll ret=1e17;
    int m = (l+r)/2;
    if(lz[rt])
    {
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt];
        mx[rt<<1]+=lz[rt],mx[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    if(m>=L) ret=min(ret,query(L,R,l,m,rt<<1));
    if(m< R) ret=min(ret,query(L,R,m+1,r,rt<<1|1));
    return ret;
}
int n,q;
ll ans[maxn];
void dfs2(int u)
{
    for(qry qq:qr[u]) ans[qq.id] = query(id[qq.l],id[qq.r],1,n,1);
    for(edge e:g[u])
    {
        int v=e.v,w=e.w;
        update(id[1],id[n],w,1,n,1);
        update(id[v],id[v]+sz[v]-1,-2ll*w,1,n,1);
        dfs2(v);
        update(id[1],id[n],-w,1,n,1);
        update(id[v],id[v]+sz[v]-1,2ll*w,1,n,1);
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=2;i<=n;++i)
    {
        int p,w;
        cin>>p>>w;
        g[p].push_back({i,w});
    }
    for(int i=1;i<=n;++i) sort(all(g[i]));
    dfs(1);
    build(1,n,1);
    for(int i=1;i<=q;++i)
    {
        int u,l,r;
        cin>>u>>l>>r;
        qr[u].push_back({l,r,i});
    }
    dfs2(1);
    for(int i=1;i<=q;++i) cout<<ans[i]<<endl;
}