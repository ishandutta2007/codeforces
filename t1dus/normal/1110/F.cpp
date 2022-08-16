#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define vpii vector<pii>
#define FORD(i,a,b) for(int i = a; i >= b; i --)
#define remin(a,b) a = min(a,b)

const int MAXN = 500005;
const int INF = (int)(1e16);
 
int n,q,h;
vpii adj[MAXN];
pii par[MAXN];
int dist[MAXN]; 
int fin[MAXN];
int tim;
int seg[2*MAXN],lazy[MAXN];
int ans[MAXN];
vector<pair<pii,int> > queries[MAXN];

void dfs(int u,int d){
    dist[u] = d;
    tim++;
    if(adj[u].empty()){
        seg[u+n] = d;
    }
    else{
        seg[u+n] = INF;
    }
    for(auto v:adj[u]){
        dfs(v.F,d+v.S);
    }
    fin[u] = tim;
}

void apply(int p,int val){
    seg[p] += val;
    if(p < n) lazy[p] += val;
}

void build(int p){
    while(p > 1){
        p /= 2;
        seg[p] = lazy[p]+min(seg[p*2],seg[p*2+1]);
    }
}

void push(int p){
    FORD(s,h,1){
        int ind = (p>>s);
        if(lazy[ind]){
            apply(ind*2,lazy[ind]);
            apply(ind*2+1,lazy[ind]);
            lazy[ind] = 0;
        }
    }
}

void inc(int l,int r,int val){
    l += n;
    r += n;
    int l0 = l,r0 = r;
    while(l < r){
        if(l%2) apply(l++,val);
        if(r%2) apply(--r,val);
        l /= 2;
        r /= 2;
    }
    build(l0);
    build(r0-1);
}

int query(int l,int r){
    l += n;
    r += n;
    push(l);
    push(r-1);
    int res = INF;
    while(l < r){
        if(l%2) remin(res,seg[l++]);
        if(r%2) remin(res,seg[--r]);
        l /= 2;
        r /= 2;
    }
    return res;
}

void solve(int u){
    for(auto x:queries[u]){
        ans[x.S] = query(x.F.F,x.F.S);
    }
    for(auto v:adj[u]){
        inc(0,n,v.S);
        inc(v.F,fin[v.F],-2*v.S);
        solve(v.F);
        inc(0,n,-v.S);
        inc(v.F,fin[v.F],2*v.S);
    }
}

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    h = sizeof(int) * 8 - __builtin_clz(n);
    FOR(i,1,n){
        int p,w; cin >> p >> w; p --;
        par[i] = {p,w};
        adj[p].pb({i,w});
    }
    tim = 0;
    dfs(0,0);
    FORD(i,n-1,1) seg[i] = min(seg[2*i],seg[2*i+1]);
    REP(i,q){
        int u,l,r; cin >> u >> l >> r; u --; l --;
        queries[u].pb({{l,r},i});
    }
    solve(0);
    REP(i,q){
        cout << ans[i] << "\n";
    }
}