#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 3e6+5;
using cd = complex<double>;
const int LOG = 27;
const double PI = acos(-1);
vector<int> dist, depth;
vector<int> basis(LOG);
vector<vector<pair<int, int>>> adj;
void insert(int msk) {
  for(int i = LOG - 1; i >= 0; i--) {
    if((msk & (1 << i)) == 0) continue;
    if(!basis[i]) {
      basis[i] = msk;
      return;
    }
    msk ^= basis[i];
  }
}
void dfs(int curr, int par) {
  for(auto next : adj[curr]) {
    if(depth[next.f] == 0) {
      depth[next.f] = depth[curr] + 1;
      dist[next.f] = dist[curr] ^ next.s;
      dfs(next.f, curr);
    }
    else if(depth[next.f] <= depth[curr]) {
      int pathXOR = dist[curr] ^ dist[next.f] ^ next.s;
      insert(pathXOR);
    }
  }
}
int main() {
  int n, m; cin >> n >> m;
  adj.resize(n);
  for(int i = 0; i < m; i++) {
    int x, y, w; cin >> x >> y >> w;
    --x, --y;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
  depth.resize(n), dist.resize(n);
  depth[0] = 1;
  dfs(0, -1);
  int x = dist[n - 1];
  for(int i = LOG - 1; i >= 0; i--) {
    if(!basis[i]) continue;
    if(x & (1 << i)) 
      x ^= basis[i];
  }
  cout << x << "\n";
}