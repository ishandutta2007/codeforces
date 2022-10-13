#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second
vector<vector<int>> adj;
vector<int> sz, st, parent;
vector<vector<int>> tab;
vector<int> depth;
int x;
void dfs(int curr, int par) {
  st[curr] = x++;
  sz[curr] = 1;
  for(int next : adj[curr]) {
    if(next == par) continue;
    parent[next] = curr;
    tab[next][0] = curr;
    depth[next] = depth[curr] + 1;
    dfs(next, curr);
    sz[curr] += sz[next];
  }
}
bool isPar(int x, int y) {
  return st[x] <= st[y] && st[x] + sz[x] >= st[y] + sz[y];
}
int lca(int u, int v) {
  if(depth[u] < depth[v]) swap(u, v);
  for(int b = 19; b >= 0; b--)
    if(depth[u] - (1 << b) >= depth[v])
      u = tab[u][b];
  if(u == v) return u;
  for(int b = 19; b >= 0; b--)
    if(tab[v][b] != tab[u][b])
      v = tab[v][b], u = tab[u][b];
  return tab[u][0];
}
int dist(int u, int v) {
  return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
int getSz(int x, int y) {
    if(x != 0) return sz[x];
    int diff = depth[y] - 1;
    for(int b = 19; b >= 0; b--) {
        if((1 << b) <= diff) {
            y = tab[y][b];
            diff -= (1 << b);
        }
    }
    return sz[x] - sz[y];
}
int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    adj.clear(), adj.resize(n);
    sz.clear(), sz.resize(n);
    st.clear(), st.resize(n);
    parent.clear(), parent.resize(n);
    depth.clear(), depth.resize(n);
    for(int i = 0; i < n - 1; i++) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v), adj[v].push_back(u);
    }
    x = 0;
    tab.resize(n, vector<int>(20));
    dfs(0, -1);
    for(int j = 1; j < 20; j++) {
      for(int i = 0; i < n; i++) {
        tab[i][j] = tab[ tab[i][j-1] ][j-1];
      }
    }
    vector<ll> ans(n + 1);
    for(int next : adj[0]) {
      ans[0] += sz[next]*1LL*(sz[next] - 1)/2;
    }
    int left = 0, right = 0;
    //fails when left = right = 0?
    //find ans[1] manually
    vector<int> in;
    for(int next : adj[0]) {
      if(isPar(next, 1)) in.push_back(sz[next] - sz[1]);
      else in.push_back(sz[next]);
    }
    for(auto &it : in) {
      ans[1] -= it*1LL*(it - 1)/2;
    }
    ans[1] += (sz[0] - sz[1])*1LL*(sz[0] - sz[1] - 1)/2;
    left = 1;
    for(int i = 1; i < n; i++) {
      if(i == n - 1) {
        ans[i + 1] = getSz(left, right)*1LL*getSz(right, left);
        continue;
      }
      if(right == 0) {
        if(isPar(left, i + 1)) {
          ans[i + 1] = (getSz(left, right) - getSz(i + 1, right))*1LL*(getSz(right, left));
          left = i + 1;
        }
        else if(lca(i + 1, left) == 0) {
					ans[i + 1] = (getSz(right, left) - getSz(i + 1, left))*1LL*(getSz(left, right));
		      right = i + 1;
        }
        else if(dist(i + 1, left) + dist(i + 1, right) == dist(left, right)) {
          ans[i + 1] = 0;
        }
        else {
          ans[i + 1] = getSz(left, right)*1LL*getSz(right, left);
          break;
        }
      }
      else {
          if(isPar(left, i + 1)) {
            ans[i + 1] = (getSz(left, right) - getSz(i + 1, right))*1LL*(getSz(right, left));
            left = i + 1;
          }
          else if(isPar(right, i + 1)) { // 3
					  ans[i + 1] = (getSz(right, left) - getSz(i + 1, left))*1LL*(getSz(left, right));
		        right = i + 1;
          }
          else if(dist(i + 1, left) + dist(i + 1, right) == dist(left, right)) {
            ans[i + 1] = 0;
          }
          else {
            ans[i + 1] = getSz(left, right)*1LL*getSz(right, left);
            break;
          }
      }
      
    }
    for(int i = 0; i <= n; i++)
      cout << ans[i] << " ";
    cout << "\n";
  }
}