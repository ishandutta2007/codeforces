#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 1;
const int A = 26;

int c[N], to[N][A], sub[N];
vector<int> adj[N];
string s;

int merge(int u, int v) {
  if (u == 0 || v == 0) {
    return u + v;
  }

  sub[u] = 1;
  for (int i = 0; i < A; ++i) {
    to[u][i] = merge(to[u][i], to[v][i]);
    sub[u] += sub[to[u][i]];
  }

  return u;
}

array<int, 2> dfs(int u, int p = 0) {
  array<int, 2> ans = {0, 0};
  for (auto c : adj[u]) {
    if (c != p) {
      array<int, 2> child = dfs(c, u);
      if (child[0] == ans[0]) {
        ans[1] += child[1];
      } else {
        ans = max(ans, child);
      }
      int l = s[c - 1] - 'a';
      to[u][l] = merge(to[u][l], c);
    }
  }

  sub[u] = 1;
  for (int i = 0; i < A; ++i) {
    sub[u] += sub[to[u][i]];
  }

  if (c[u] + sub[u] == ans[0]) {
    ++ans[1];
  } else if (c[u] + sub[u] > ans[0]) {
    ans = {c[u] + sub[u], 1};
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  cin >> s;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  array<int, 2> ans = dfs(1);

  cout << ans[0] << "\n";
  cout << ans[1] << "\n";
}