#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, int, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
vector<vector<int>> adj;
vector<int> depth;
vector<int> back, id;
vector<pair<int, int>> edges;
void cmp(int &x, int y) {
  if(depth[y] < depth[x]) x = y;
}
map<pair<int, int>, int> dir;
void dfs(int curr) {
  back[curr] = curr;
  for(int next : adj[curr]) {
    if(depth[next] == 0) {
      depth[next] = depth[curr] + 1;
      dfs(next);
      cmp(back[curr], back[next]);
    }
    else if(depth[next] < depth[curr] - 1) {
      dir[make_pair(curr, next)] = 1;
      dir[make_pair(next, curr)] = -1;
      cmp(back[curr], next);
    }
  }
}
void dfs2(int curr) {
  id[curr] = id[back[curr]];
  for(int next : adj[curr]) {
    if(depth[next] == depth[curr] + 1)
      dfs2(next);
  }
}
vector<bool> vis;
void dfs3(int curr, int par) {
  vis[curr] = true;
  for(int next : adj[curr]) {
    if(abs(depth[next] - depth[curr]) == 1) { //adj in dfs tree
      if(!vis[next]) {
        dir[make_pair(curr, next)] = 1;
        dir[make_pair(next, curr)] = -1;
        dfs3(next, curr);
      }
    }
  }
}
int main() {
  int n, m; cin >> n >> m;
  adj.resize(n), depth.resize(n);
  back.resize(n), id.resize(n);
  for(int i=0;i<m;i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.push_back({u, v});
  }
  depth[0] = 1;
  dfs(0);
  for(int i=0;i<n;i++)
    id[i] = i;
  dfs2(0);
  vector<int> num(n);
  for(int i=0;i<n;i++)
    ++num[id[i]];
  int ans = 0;
  for(int i=0;i<n;i++) {
    if(num[i] > num[ans])
      ans = i;
  }
  int st = 0;
  int d = 10000000;
  for(int i=0;i<n;i++) {
    if(id[i] == ans && depth[i] < d)
      st = i, d = depth[i];
  }
  vis.resize(n);
  dfs3(st, -1);
  cout << num[ans] << "\n";
  for(int i=0;i<m;i++) {
    int x = edges[i].f, y = edges[i].s;
    if(dir[make_pair(x, y)] == 1) cout << y+1 << " " << x+1 << "\n";
    else cout << x+1 << " " << y+1 << "\n";
  }
}