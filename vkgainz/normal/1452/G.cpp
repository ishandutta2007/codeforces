#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
struct lca_lift {
  const int lg = 20;
  int n;
  vector<int> depth;
  vector<vector<int> > edges;
  vector<vector<int> > lift;

  void init(int sz) {
    n = sz;
    depth = vector<int>(n);
    edges = vector<vector<int> >(n, vector<int>());
    lift = vector<vector<int> >(n, vector<int>(lg, -1));
  }

  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  void attach(int node_to_attach, int node_to_attach_to) {
    int a = node_to_attach, b = node_to_attach_to;
    edge(a, b);

    lift[a][0] = b;

    for(int i = 1; i < lg; i++) {
      if(lift[a][i - 1] == -1) lift[a][i] = -1;
      else lift[a][i] = lift[ lift[a][i-1] ][i-1];
    }

    depth[a] = depth[b] + 1;
  }

  void init_lift(int v = 0) {
    depth[v] = 0;
    dfs(v, -1);
  }

  void dfs(int v, int par) {
    lift[v][0] = par;
    for(int i = 1; i < lg;i++) {
      if(lift[v][i-1]==-1) lift[v][i] = -1;
      else lift[v][i] = lift[lift[v][i-1]][i-1];
    }

    for(int x : edges[v]) {
      if(x!=par) {
        depth[x] = depth[v]+1;
        dfs(x, v);
      }
    }
  }

  int get(int v, int k) {
    for(int i=lg-1;i>=0;i--) {
      if(v==-1) return v;
      if((1<<i) <=k) {
        v = lift[v][i];
        k-=(1<<i);
      }
    }
    return v;
  }
  int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    int v = get(a, d);
    if(v == b) return v;
    for(int i=lg-1;i>=0;i--) {
      if(lift[v][i]!=lift[b][i]) {
        v = lift[v][i];
        b = lift[b][i];
      }
    }
    return lift[b][0];
  }
  int get_dist(int a, int b) {
    int v = get_lca(a, b);
    return depth[a] + depth[b] - 2*depth[v];
  }
};
struct centroid {
  vector<vector<int> > edges;
  vector<bool> vis;
  vector<int> par;
  vector<int> sz;
  int n;
  void init(int s) {
    n = s;
    edges=  vector<vector<int> >(n, vector<int>());
    vis = vector<bool>(n, 0);
    par = vector<int>(n);
    sz = vector<int>(n);
  }
  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int find_size(int v, int p = -1) {
    if (vis[v]) return 0;
    sz[v] = 1;
    for(int x : edges[v]) {
      if(x != p) {
        sz[v] += find_size(x, v);
      }
    }
    return sz[v];
  }
  int find_centroid(int v, int p, int n) {
    for(int x : edges[v]) {
      if(x != p) {
        if(!vis[x] && sz[x] > n / 2) {
          return find_centroid(x, v, n);
        }
      }
    }
    return v;
  }
  void init_centroid(int v = 0, int p = -1) {
    find_size(v);

    int c = find_centroid(v, -1, sz[v]);
    vis[c] = true;
    par[c] = p;

    for(int x : edges[c]) {
      if(!vis[x]) {
        init_centroid(x, c);
      }
    }
  }
};
lca_lift lca;
centroid ct;
int ans[MX], a[MX];
int nearest[MX];
vector<int> adj[MX];
bool seen[MX];
map<int, int> upd_subtree[MX];
void add_in(int v, int x, int d) {
  auto it = upd_subtree[v].lower_bound(d);
  if(it != upd_subtree[v].end()) {
    if(it->s>=x) return;
  }
  --it;
  while(it!=upd_subtree[v].begin() && it->s <= x) {
    upd_subtree[v].erase(it--);
  }
  upd_subtree[v][d] = x;
}
void query(int v) {
  int u = v;
  while(ct.par[u] != -1) {
    u = ct.par[u];
    auto it = upd_subtree[u].lower_bound(lca.get_dist(u, v));
    if(it==upd_subtree[u].end()) continue;
    ans[v] = max(ans[v], it->s);
  }
}
vector<pair<int, int>> toAdd[MX];
void upd(int v, int d, int x) {
  if(d<0 || x<0) return;
  ans[v] = max(ans[v], x);
  toAdd[v].push_back({x, d});
  int u = v;
  while(ct.par[u] != -1) {
    u = ct.par[u];
    int cmp = lca.get_dist(u, v);
    if(cmp <= d) {
      ans[u] = max(ans[u], x);
      toAdd[u].push_back({x, d - cmp});
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  lca.init(n);
  ct.init(n);
  for(int i=0;i<n-1;i++) {
    int u,v; cin >> u >> v;
    --u, --v;
    lca.edge(u, v);
    ct.edge(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int k; cin >> k;
  for(int i=0;i<k;i++) cin >> a[i], --a[i];
  lca.init_lift();
  ct.init_centroid();
  queue<int> q;
  for(int i=0;i<n;i++) nearest[i] = 1000000;
  for(int i=0;i<k;i++) {
    nearest[a[i]] = 0;
    q.push(a[i]);
  }
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(int next : adj[curr]) {
      if(nearest[curr] + 1 < nearest[next]) {
        nearest[next] = nearest[curr] + 1;
        q.push(next);
      }
    }
  }
  for(int i=0;i<n;i++) upd_subtree[i][-1] = 1000000;
  for(int i=0;i<n;i++) upd(i, nearest[i] - 1, nearest[i]);
  for(int i=0;i<n;i++) {
    for(pair<int, int> x : toAdd[i]) {
      add_in(i, x.f, x.s);
    }
  }
  for(int i=0;i<n;i++) query(i);
  for(int i=0;i<n;i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}