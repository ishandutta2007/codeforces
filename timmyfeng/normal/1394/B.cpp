#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(uint64_t(new char));

const int N = 2e5 + 1;
const int K = 10;

vector<pair<int, int>> adj[N];
long long mask[K][K];
long long hsh[N];
long long target;
long long cur;
int k;

int solve(int i) {
  if (i > k)
    return cur == target;
  int res = 0;
  for (int j = 1; j <= i; ++j) {
    cur ^= mask[i][j];
    res += solve(i + 1);
    cur ^= mask[i][j];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m >> k;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(w, v);
  }

  for (int i = 1; i <= n; ++i) {
    hsh[i] = rng();
    target ^= hsh[i];
  }

  for (int i = 1; i <= n; ++i) {
    int s = adj[i].size();
    sort(adj[i].begin(), adj[i].end());
    for (int j = 0; j < s; ++j) {
      mask[s][j + 1] ^= hsh[adj[i][j].second];
    }
  }

  cout << solve(1) << "\n";
}