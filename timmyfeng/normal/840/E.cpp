#include <bits/stdc++.h>
using namespace std;

const int N = 50'000;
const int B = 1 << 8;

vector<int> adj[N];
int a[N];

int ancestor[N];
int best[N][B];
int dep[N];
int par[N];

int trie[2 * B][2];

void dfs(int u) {
  for (auto c : adj[u]) {
    if (c != par[u]) {
      dep[c] = dep[u] + 1;
      par[c] = u;
      dfs(c);
    }
  }

  if (dep[u] >= B - 1) {
    for (int i = 0; i < 2 * B; ++i) {
      for (int j = 0; j < 2; ++j) {
        trie[i][j] = -1;
      }
    }
    int size = 1;

    int v = u;
    for (int i = 0; i < B; ++i) {
      int right = (a[v] ^ i) % B;
      int left = (a[v] ^ i) / B;

      int cur = 0;
      for (int j = B / 2; j > 0; j /= 2) {
        int nxt = ((left & j) > 0);
        if (trie[cur][nxt] == -1) {
          trie[cur][nxt] = size;
          ++size;
        }
        cur = trie[cur][nxt];
      }
      trie[cur][0] = max(trie[cur][0], right);

      v = par[v];
    }

    for (int i = 0; i < B; ++i) {
      int cur = 0;
      int res = B - 1;
      for (int j = B / 2; j > 0; j /= 2) {
        int nxt = ((i & j) == 0);
        if (trie[cur][nxt] != -1) {
          cur = trie[cur][nxt];
        } else {
          cur = trie[cur][nxt ^ 1];
          res ^= j;
        }
      }
      best[u][i] = res * B + trie[cur][0];
    }

    ancestor[u] = v;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  par[0] = -1;
  dfs(0);

  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    int d = 0;
    int ans = -1;
    while (v != -1 && dep[u] + B - 1 <= dep[v]) {
      ans = max(ans, best[v][d]);
      v = ancestor[v];
      ++d;
    }

    d *= B;
    while (v != -1 && dep[u] <= dep[v]) {
      ans = max(ans, a[v] ^ d);
      v = par[v];
      ++d;
    }

    cout << ans << "\n";
  }
}