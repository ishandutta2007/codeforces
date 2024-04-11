#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<tuple<int, int, int>> adj[N];
long long weight[N];
long long cur;
int cost[N];
int cnt[N];

int dfs(int u, int p, long long d) {
  if (u != 1 && adj[u].size() == 1u) {
    cnt[u] = 1;
    cur += d;
  }

  for (auto [c, w, t] : adj[u]) {
    if (c != p) {
      cost[c] = t;
      weight[c] = w;
      cnt[u] += dfs(c, u, d + w);
    }
  }
  return cnt[u];
}

void solve() {
  int n;
  long long s;
  cin >> n >> s;

  fill(adj, adj + n + 1, vector<tuple<int, int, int>>());
  fill(weight, weight + n + 1, 0);
  fill(cnt, cnt + n + 1, 0);

  for (int i = 0; i < n - 1; ++i) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    adj[u].emplace_back(v, w, c);
    adj[v].emplace_back(u, w, c);
  }

  cur = 0;
  dfs(1, 0, 0);

  vector<long long> pre_sum1 = {0};
  vector<long long> pre_sum2 = {0};
  for (int i = 2; i <= n; ++i) {
    while (weight[i] > 0) {
      long long delta = (weight[i] + 1) / 2 * cnt[i];
      if (cost[i] == 1) {
        pre_sum1.push_back(delta);
      } else {
        pre_sum2.push_back(delta);
      }
      weight[i] /= 2;
    }
  }

  sort(pre_sum1.rbegin(), pre_sum1.rend() - 1);
  sort(pre_sum2.rbegin(), pre_sum2.rend() - 1);
  for (int i = 1; i < int(pre_sum1.size()); ++i) {
    pre_sum1[i] += pre_sum1[i - 1];
  }
  for (int i = 1; i < int(pre_sum2.size()); ++i) {
    pre_sum2[i] += pre_sum2[i - 1];
  }

  int ans = 2e9;
  int j = pre_sum2.size() - 1u;
  for (int i = 0; i < int(pre_sum1.size()); ++i) {
    while (j > 0 && cur - pre_sum1[i] - pre_sum2[j - 1] <= s) {
      --j;
    }
    if (cur - pre_sum1[i] - pre_sum2[j] <= s) {
      ans = min(ans, i + 2 * j);
    }
  }

  cout << ans << "\n";
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