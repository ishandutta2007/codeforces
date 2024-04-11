#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;
const int A = 1000000;

int cheat[N], sub[N], maxi[N][2], sum[N];
vector<int> adj[N];
bool good[N];

void dfs_pull(int u, int p = 0) {
  sub[u] = 1;
  sum[u] = maxi[u][0] = maxi[u][1] = 0;
  for (auto c : adj[u]) {
    if (c != p) {
      dfs_pull(c, u);
      sub[u] += sub[c];
      if (cheat[c] == sub[c]) {
        sum[u] += cheat[c];
      } else if (cheat[c] > maxi[u][0]) {
        maxi[u][1] = maxi[u][0];
        maxi[u][0] = cheat[c];
      } else if (cheat[c] > maxi[u][1]) {
        maxi[u][1] = cheat[c];
      }
    }
  }
  cheat[u] = good[u] ? 1 + sum[u] + maxi[u][0] : 0;
}

int dfs_push(int u, int p = 0) {
  int res = cheat[u];
  for (auto c : adj[u]) {
    if (c != p) {
      int subu = sub[u];
      int sumu = sum[u];
      int cheatu = cheat[u];
      int maxiu = maxi[u][0];

      sub[u] -= sub[c];
      if (cheat[c] == sub[c]) {
        sum[u] -= cheat[c];
      } else if (cheat[c] == maxi[u][0]) {
        maxi[u][0] = maxi[u][1];
      }
      cheat[u] = good[u] ? 1 + sum[u] + maxi[u][0] : 0;

      int subc = sub[c];
      int sumc = sum[c];
      int cheatc = cheat[c];
      int maxic = maxi[c][0];

      sub[c] += sub[u];
      if (cheat[u] == sub[u]) {
        sum[c] += cheat[u];
      } else if (cheat[u] > maxi[c][0]) {
        maxi[c][1] = maxi[c][0];
        maxi[c][0] = cheat[u];
      } else if (cheat[u] > maxi[c][1]) {
        maxi[c][1] = cheat[u];
      }
      cheat[c] = good[c] ? 1 + sum[c] + maxi[c][0] : 0;

      res = max(res, dfs_push(c, u));

      sub[c] = subc;
      sum[c] = sumc;
      cheat[c] = cheatc;
      maxi[c][0] = maxic;

      sub[u] = subu;
      sum[u] = sumu;
      cheat[u] = cheatu;
      maxi[u][0] = maxiu;
    }
  }
  return res;
}

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int l = 1, r = A;
  while (l < r) {
    int m = (l + r + 1) / 2;

    for (int i = 1; i <= n; ++i) {
      good[i] = (a[i] >= m);
    }

    dfs_pull(1);
    if (dfs_push(1) >= k) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  cout << r << "\n";
}