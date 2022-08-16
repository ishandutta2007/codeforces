#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define FORD(i,a,b) for(int i = a; i >= b; i --)
#define vi vector<int>
#define pb push_back

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int MX = 300005;

int n,q;
int a[MX],b[MX];
vi adj[MX];
int dep[MX],par[MX][21];
int root[MX];

int SZ = 1;

struct node{
    int val,lft,rgt;
    node(){
        val = 0;
        lft = -1;
        rgt = -1;
    }
} seg[100*MX];

void build(int ind,int l,int r,int pos,int val){
    if(l == r){
        if(l == pos) seg[ind].val = val;
        return;
    }
    seg[ind].lft = ++SZ;
    seg[ind].rgt = ++SZ;
    int m = (l+r)/2;
    build(seg[ind].lft,l,m,pos,val);
    build(seg[ind].rgt,m+1,r,pos,val);
    seg[ind].val = seg[seg[ind].lft].val^seg[seg[ind].rgt].val;
}

int update(int pid,int l,int r,int pos,int val){
    int id = ++SZ;
    seg[id] = seg[pid];
    seg[id].val ^= val;
    if(l == r) return id;
    int m = (l+r)/2;
    if(pos <= m){
        seg[id].lft = update(seg[pid].lft,l,m,pos,val);
    }
    else{
        seg[id].rgt = update(seg[pid].rgt,m+1,r,pos,val);
    }
    return id;
}

int query(int ind1,int ind2,int l,int r,int x,int y,int lca){
    if(r < x or l > y) return -1;
    // cout << ind1 << " " << ind2 << " " << l << " " << r << " " << x << " " << y << " " << lca << "\n";
    int val = seg[ind1].val^seg[ind2].val;
    // cout << seg[ind1].val << " " << seg[ind2].val << " " << val << "\n";
    if(l <= a[lca] and a[lca] <= r) val ^= b[a[lca]];
    // cout << val << "\n";
    if(!val) return -1;
    if(l == r) return l;
    int m = (l+r)/2;
    int ql = query(seg[ind1].lft,seg[ind2].lft,l,m,x,y,lca);
    if(ql != -1) return ql;
    return query(seg[ind1].rgt,seg[ind2].rgt,m+1,r,x,y,lca);
}

void dfs(int u,int p,int d){
    par[u][0] = p;
    dep[u] = d;
    for(auto v:adj[u]){
        if(v != p){
            root[v] = update(root[u],1,n,a[v],b[a[v]]);
            dfs(v,u,d+1);
        }
    }
}

int find_lca(int u,int v){
    if(dep[u] > dep[v]) swap(u,v);
    FORD(j,20,0){
        if(dep[v]-(1<<j) >= dep[u]) v = par[v][j];
    }
    if(u == v) return u;
    FORD(j,20,0){
        if(par[u][j] != par[v][j]){
            u = par[u][j];
            v = par[v][j];
        }
    }
    return par[u][0];
}

signed main(){
    cin >> n >> q;
    FOR(i,1,n+1){
        cin >> a[i];
        b[i] = RNG()%((1LL<<62LL)-1LL);
    }
    REP(i,n-1){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    root[1] = 1;
    build(1,1,n,a[1],b[a[1]]);
    dfs(1,1,0);
    FOR(j,1,21){
        FOR(i,1,n+1){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    REP(i,q){
        int u,v,l,r; cin >> u >> v >> l >> r;
        int lca = find_lca(u,v);
        cout << query(root[u],root[v],1,n,l,r,lca) << "\n"; 
    }
}