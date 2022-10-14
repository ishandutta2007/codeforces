#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> L(n), R(n);
  int T = 0;
  vector<int> v;
  function<void(int, int)> Dfs = [&](int u, int p) {
    L[u] = ++T;
    bool leaf = true;
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }
      leaf = false;
      Dfs(v, u);
    }
    if (leaf) {
      v.push_back(u);
    }
    R[u] = T;
  };
  Dfs(0, -1);
  auto anc = [&](int u, int v) {
    return L[u] <= L[v] && R[v] <= R[u];
  };
  int k = v.size();
  vector<int> a(k);
  vector<int> ord(n);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    --a[i];
    ord[a[i]] = i;
  }
  vector<int> mn(n, 1e9);
  for (int i = 0; i < n; i++) {
    vector<int> son;
    for (int j = 0; j < v.size(); j++) {
      if (anc(i, v[j])) {
        son.push_back(ord[v[j]]);
        mn[i] = min(mn[i], ord[v[j]]);
      }
    }
    sort(son.begin(), son.end());
    bool ok = true;
    for (int j = 0; j + 1 < son.size(); j++) {
      if (son[j] + 1 != son[j + 1]) {
        ok = false;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      return 0;
    }
  }
  vector<int> ans;
  function<void(int, int)> Rec = [&](int u, int p) {
    sort(g[u].begin(), g[u].end(), [&](int i, int j) {
      return mn[i] < mn[j];
    });
    ans.push_back(u);
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }
      Rec(v, u);
      ans.push_back(u);
    }
  };
  Rec(0, -1);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  return 0;
}