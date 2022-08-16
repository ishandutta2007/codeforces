#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second

int n,m,q;
vi adj[200005];
vector<pii> edges,bridges;
int dfs_num[200005],dfs_low[200005],dfs_par[200005];
int comp[200005];
vi g[200005];
int par[200005][19],dep[200005];
int str[200005],fin[200005],lc[200005];
int order[200005];
int mkc = 0;

bitset<200005> bridge,vis;

int tim = 1,SZ = 0;

bool ans = 1;

int adjf(int u,int bn){
  if(edges[bn].F == u) return edges[bn].S;
  return edges[bn].F;
}

void dfs_bridges(int u){
  dfs_num[u] = dfs_low[u] = tim; tim++;
  for(int bn:adj[u]){
    int v = adjf(u,bn);
    if(dfs_num[v] == 0){
      dfs_par[v] = bn;
      dfs_bridges(v);
      if(dfs_low[v] > dfs_num[u]) bridge[bn] = 1;
      dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
    else if(dfs_par[u] != bn){
      dfs_low[u] = min(dfs_low[u],dfs_num[v]);
    }
  }
}

void dfs_bt(int u){
  comp[u] = SZ;
  vis[u] = 1;
  for(auto x:adj[u]){
    if(bridge[x]) continue;
    int v = adjf(u,x);
    if(!vis[v]) dfs_bt(v);
  }
}

void dfs(int u,int p,int d = 0){
  vis[u] = 1;
  order[u] = mkc;
  par[u][0] = p;
  dep[u] = d;
  for(auto v:g[u]){
    assert(v != u);
    if(v != p) dfs(v,u,d+1);
  }
}

int lca(int u,int v){
  if(dep[u] < dep[v]) swap(u,v);
  for(int j = 18; j >= 0; j --){
    if(dep[u]-(1<<j) >= dep[v]) u = par[u][j];
  }
  if(u == v) return u;
  for(int j = 18; j >= 18; j --){
    if(par[u][j] != par[v][j]){
      u = par[u][j];
      v = par[v][j];
    }
  }
  return par[u][0];
}

void compute(int u,int p){
  for(auto v:g[u]){
    if(v != p){
      compute(v,u);
      str[u] += str[v];
      fin[u] += fin[v];
      lc[u] += lc[v];
    }
  }
  if(str[u] > lc[u] and fin[u] > lc[u]) ans = 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> q;
  for(int i = 0; i < m; i ++){
    int u,v; cin >> u >> v;
    adj[u].pb(i);
    adj[v].pb(i);
    edges.pb({u,v});
  }
  dfs_bridges(1);
  for(int i = 0; i < m; i ++){
    if(!bridge[i]) continue;
    bridges.pb(edges[i]);
    // adj[edges[i].F].erase(i);
    // adj[edges[i].S].erase(i);
  }
  for(int i = 1; i <= n; i ++){
    if(!vis[i]){
      SZ++;
      dfs_bt(i);
    }
  }
  for(auto x:bridges){
    g[comp[x.F]].pb(comp[x.S]);
    g[comp[x.S]].pb(comp[x.F]);
  }
  // if(n == 159995) {
  //   cout << "GG\n";
  //   return 0;
  // }
  vis.reset();
  for(int i = 1; i <= SZ; i ++){
    if(!vis[i]){
      dfs(i,i);
      mkc++;
    }
  }

  for(int j = 1; j <= 18; j ++){
    for(int i = 1; i <= SZ; i ++){
      par[i][j] = par[par[i][j-1]][j-1];
    }
  }
  // for(auto x:bridges){
  //   cout << x.F << " --" << x.S << endl;
  // }
  // cout << SZ << endl;
  // for(int i = 1; i <= SZ; i ++){
  //   cout << i << " - " << g[i].size() << endl;
  //   for(auto v:g[i]) cout << v << " "; cout << "\n";
  // }
  for(int i = 0; i < q; i ++){
    int u,v; cin >> u >> v;
    u = comp[u];
    v = comp[v];
    if(order[u] != order[v]){
      cout << "No\n";
      return 0;
    }
    int gg = lca(u,v);
    str[u]++;
    fin[v]++;
    lc[gg]++;
    // cout << u << " " << v << " " << gg << endl;
  }
  for(int i = 1; i <= SZ; i ++){
    if(par[i][0] == i)
    compute(i,i);
  }
  if(ans) cout << "Yes\n";
  else cout << "No\n";
}