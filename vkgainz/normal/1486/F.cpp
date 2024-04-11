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
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
map<pair<int, int>, int> sec[MX];
map<pair<int, int>, int> flow; //use gt hash table?
int numThru[MX];
int numLcaThru[MX];
vector<int> adj[MX];
int tab[MX][20];
int depth[MX];
int tabCnt[MX][20];
int totFlow[MX];
void dfs(int curr, int par) {
  if(par!=-1) tab[curr][0] = par;
  for(int next : adj[curr]) {
    if(next == par) continue;
    depth[next] = depth[curr] + 1;
    dfs(next, curr);
  }
}
void prop(int curr, int par) {
  for(int next : adj[curr]) {
    if(next == par) continue;
    prop(next, curr);
    numThru[curr] += numThru[next];
    totFlow[curr] += totFlow[next];
  }
}
int lca(int u, int v) {
  if(depth[u] < depth[v]) swap(u, v);
  for(int i=19;i>=0;i--) {
    if(depth[u] - (1<<i) >= depth[v]) u = tab[u][i];
  }
  if(u==v) return u;
  for(int i=19;i>=0;i--) {
    if(tab[u][i] == tab[v][i]) continue;
    u = tab[u][i], v = tab[v][i];
  }
  return tab[u][0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  for(int i=0;i<n-1;i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  for(int j=1;j<20;j++) {
    for(int i=0;i<n;i++) {
      tab[i][j] = tab[ tab[i][j-1] ][j-1];
    }
  }
  //to answer a query u->lca->v
  //separate into u, par[u]....lca.child + v, par[v]...lca.child & lca
  //for first/second case:
  //find sum of numLcaThru[vertex on path] - sum of going through vertex + vertex.child w vertex as lca ==> logM + preprocessing?  
  ////for third case, find number paths going through lca - number through lca.child1 - number through lca.child2 + number through lca.child1 && number through lca.child2 ==> log(M) time
  int m; cin >> m;
  vector<pair<pair<int, int>, int>> q;
  for(int i=0;i<m;i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    int l = lca(u, v);
    int temp = u;
    for(int j=19;j>=0;j--) {
      if(depth[temp] - (1<<j) > depth[l]) temp = tab[temp][j];
    }
    int x = temp;
    if(x == l) x = -1;
    if(temp != l) ++flow[make_pair(l, temp)];
    temp = v;
    for(int j=19;j>=0;j--) {
      if(depth[temp] - (1<<j) > depth[l]) temp = tab[temp][j];
    }
    int y = temp;
    if(y == l) y = -1;
    if(temp != l) ++flow[make_pair(l, temp)];
    if(x>=0 && y>=0) ++sec[l][make_pair(x, y)], ++sec[l][make_pair(y, x)];
    ++numThru[u];
    ++numThru[v];
    --numThru[l];
    if(l != 0) --numThru[tab[l][0]];
    ++numLcaThru[l];
    q.push_back({{u, v}, l});
    ++totFlow[u];
    ++totFlow[v];
    --totFlow[l];
    --totFlow[l];
  }
  prop(0, -1);
  for(int i=0;i<n;i++) {
    tabCnt[i][0] += numLcaThru[i];
    if(tab[i][0]!=-1) {
      tabCnt[i][0] -= flow[make_pair(tab[i][0], i)];
    }
  }
  for(int j=1;j<20;j++) {
    for(int i=0;i<n;i++) {
      tabCnt[i][j] = tabCnt[i][j-1] + tabCnt[tab[i][j-1]][j-1];
    }
  }
  ll ans = 0LL;
  for(int i=0;i<m;i++) {
    int u = q[i].f.f, v = q[i].f.s, l = q[i].s;
    int curr = 0;
    if(u == v) {
      //case
      curr += numThru[u] - 1;
      ans += curr;
      continue;
    }
    int temp = u;
    int x = u;
    for(int j=19;j>=0;j--) {
      if(depth[temp] - (1<<j) > depth[l]) {
        curr += tabCnt[temp][j];
        temp = tab[temp][j];
      }
      if(depth[x] - (1<<j) > depth[l]) x = tab[x][j];
    }
    if(x == l) x = -1;
    temp = v;
    int y = v;
    for(int j=19;j>=0;j--) {
      if(depth[temp] - (1<<j) > depth[l]) {
        curr += tabCnt[temp][j];
        temp = tab[temp][j];
      }
      if(depth[y] - (1<<j) > depth[l]) y = tab[y][j];
    }
    //add stuff
    if(y == l) y = -1;
    if(x>=0) curr += numLcaThru[x];
    if(y>=0) curr += numLcaThru[y];
    if(x>=0) curr -= totFlow[x];
    if(y>=0) curr -= totFlow[y];
    curr += numThru[l];
    if(x>=0 && y>=0) curr+=sec[l][make_pair(x, y)];
    ans += curr;
    //cout << curr << "\n";
  }
  cout << ans/2 << "\n";
}