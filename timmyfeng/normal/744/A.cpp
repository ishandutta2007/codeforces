#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 1;

vector<int> adj[N];
int government[N];
bool visited[N];

int dfs(int u) {
  int sub = 1;
  visited[u] = true;
  for (auto c : adj[u]) {
    if (!visited[c]) {
      sub += dfs(c);
    }
  }
  return sub;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < k; ++i) {
    cin >> government[i];
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0;
  int big = 0;

  for (int i = 0; i < k; ++i) {
    int size = dfs(government[i]);
    ans += size * (size - 1) / 2;
    big = max(big, size);
    n -= size;
  }

  ans -= big * (big - 1) / 2;
  big += n;
  ans += big * (big - 1) / 2;
  ans -= m;

  cout << ans << "\n";
}