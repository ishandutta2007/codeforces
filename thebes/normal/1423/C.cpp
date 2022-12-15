#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e4+5;
int N, K, i, x, y, sz[MN], mx[MN], ct, c[MN], dp[MN];
vi adj[MN], elem[2]; vector<pii> ans;

int dfs(int n,int p){
    sz[n] = 1; mx[n] = 0;
    for(auto v : adj[n]){
        if(v==p||c[v]) continue;
        sz[n] += dfs(v, n);
        mx[n] = max(mx[n], sz[v]);
    }
    return sz[n];
}

void dfs2(int n,int p,int tot){
    if(2*mx[n]<=tot&&2*(tot-sz[n])<=tot) ct = n;
    for(auto v : adj[n]){
        if(v==p||c[v]) continue;
        dfs2(v, n, tot);
    }
}

void op(int n,int p,int r){
    if(r^p) ans.pb({n,r});
    for(auto v : adj[n]){
        if(v==p||c[v]) continue;
        op(v, n, r);
    }
}

void op2(int n,int p,int d){
    elem[d].pb(n);
    for(auto v : adj[n]){
        if(v==p||c[v]) continue;
        op2(v, n, d^1);
    }
}

void solve(int n){
    dfs2(n, 0, dfs(n, 0));
    int cur = ct;
    c[cur] = 1;
    dfs(cur, 0);
    pii big(-1,-1);
    for(auto v : adj[cur]){
        if(c[v]) continue;
        if(sz[v]>big.F) big={sz[v],v};
    }
    for(int i=0;i<2;i++)
        elem[i].clear();
    for(auto v : adj[cur]){
        if(c[v]) continue;
        if(v==big.S) op2(v, cur, 0);
        else op(v, cur, cur);
    }
    int idx = 0;
    if(elem[1].size()<elem[0].size()) idx=1;
    for(auto v : elem[idx]){
        if(v!=big.S) ans.pb({cur, v});
    }
    for(auto v : adj[cur]){
        if(c[v]) continue;
        solve(v);
    }
}

int main(){
    scanf("%d%d",&N,&K);
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    solve(1);
    assert(10*N>=ans.size());
    printf("%d\n",(int)ans.size());
    for(auto v : ans)
        printf("%d %d\n",v.F,v.S);
    return 0;
}