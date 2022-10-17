#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 100005;
vector<int> g[maxn];
int f[maxn][20], dep[maxn], a[maxn], id[maxn], sz[maxn], dcnt=0;
void dfs(int u,int fa) {
    id[u]=++dcnt;sz[u]=1;
    for(int v : g[u]) {
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        for(int i=1;i<=19;++i) f[v][i] = f[f[v][i-1]][i-1];
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int lca(int u,int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int d=dep[u]-dep[v],i=19;i>=0;--i) if(d&(1<<i)) u=f[u][i];
    if(u == v) return u;
    for(int i=19;i>=0;--i) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
ll s[maxn<<2],lz[maxn<<2];
void update(int L,int R,int v,int l,int r, int rt) {
    if(L<=l && r<=R) {
        s[rt]+=1ll*v*(r-l+1);
        lz[rt]+=v;
        return;
    }
    int m=(l+r)/2;
    if(lz[rt]) {
        lz[rt<<1]+=lz[rt];lz[rt<<1|1]+=lz[rt];
        s[rt<<1]+=lz[rt]*(m-l+1);s[rt<<1|1]+=lz[rt]*(r-m);
        lz[rt]=0;
    }
    if(L<=m) update(L,R,v,l,m,rt<<1);
    if(m<R) update(L,R,v,m+1,r,rt<<1|1);
    s[rt]=s[rt<<1]+s[rt<<1|1];
}
ll query(int p,int l,int r,int rt) {
    if(l==r) return s[rt];
    int m=(l+r)/2;
    if(lz[rt]) {
        lz[rt<<1]+=lz[rt];lz[rt<<1|1]+=lz[rt];
        s[rt<<1]+=lz[rt]*(m-l+1);s[rt<<1|1]+=lz[rt]*(r-m);
        lz[rt]=0;
    }
    if(p<=m) return query(p,l,m,rt<<1);
    return query(p,m+1,r,rt<<1|1);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i],a[i]=abs(a[i]);
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i) update(id[i],id[i]+sz[i]-1,a[i],1,n,1);
    while(q--) {
        int op,u,v;
        cin>>op>>u>>v;
        if(op==1) {
            update(id[u],id[u]+sz[u]-1,-a[u],1,n,1);
            a[u]=abs(v);
            update(id[u],id[u]+sz[u]-1,a[u],1,n,1);
        } else {
            int p=lca(u,v);
            ll ans=query(id[u],1,n,1)+query(id[v],1,n,1);
            if(p!=1) ans-=2*query(id[f[p][0]],1,n,1);
            ans-=a[p];
            ans*=2;
            ans-=a[u],ans-=a[v];
            cout<<ans<<'\n';
        }
    }
}