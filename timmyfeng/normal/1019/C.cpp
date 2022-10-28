#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 1;
 
vector<int> adj[N];
bool dead[N];
bool bad[N];
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  vector<int> stk;
  for (int u = 1; u <= n; ++u) {
    if (!dead[u]) {
      stk.push_back(u);
      dead[u] = true;
      for (int c : adj[u]) {
        dead[c] = true;
      }
    }
  }

  vector<int> ans;
  while (!stk.empty()) {
    int u = stk.back();
    stk.pop_back();
    if (!bad[u]) {
      ans.push_back(u);
      for (int c : adj[u]) {
        bad[c] = true;
      }
    }
  }

  cout << ans.size() << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}