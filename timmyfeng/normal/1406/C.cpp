#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

vector<int> adj[N];
int sub[N];
int n;

int dfs(int u, int p) {
  sub[u] = 1;
  int ans = -1;
  for (auto c : adj[u]) {
    if (c != p) {
      int chd = dfs(c, u);
      if (2 * sub[c] == n) {
        ans = c;
      } else if (chd != -1) {
        ans = chd;
      }
      sub[u] += sub[c];
    }
  }
  return ans;
}

bool dfs_ans(int u, int p, int b) {
  for (auto c : adj[u]) {
    if (c != p && c != b) {
      if (adj[c].size() == 1u) {
        cout << c + 1 << " " << u + 1 << "\n";
        cout << c + 1 << " " << b + 1 << "\n";
        return true;
      }
      if (dfs_ans(c, u, b)) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  cin >> n;
  fill(adj, adj + n, vector<int>());

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int root = 0;
  while (adj[root].size() == 1u) {
    ++root;
  }

  int bad = dfs(root, -1);
  if (bad == -1) {
    cout << 1 << " " << adj[0][0] + 1 << "\n";
    cout << 1 << " " << adj[0][0] + 1 << "\n";
    return;
  }

  assert(dfs_ans(root, -1, bad));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}