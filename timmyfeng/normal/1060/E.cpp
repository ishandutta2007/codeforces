#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

int color[N], sub[N], n;
long long freq[2], ans;
vector<int> adj[N];

void dfs(int u, int p = 0) {
  sub[u] = 1;
  ++freq[color[u]];
  for (auto c : adj[u]) {
    if (c != p) {
      color[c] = 1 - color[u];
      dfs(c, u);
      sub[u] += sub[c];
      ans += (long long) (n - sub[c]) * sub[c];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  ans += (long long) freq[0] * freq[1];
  ans /= 2;

  cout << ans << "\n";
}