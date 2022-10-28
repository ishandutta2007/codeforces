#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<pair<int, int>> adj[N];
long long weight[N];
long long cur;
int cnt[N];

int dfs(int u, int p, long long d) {
  if (u != 1 && adj[u].size() == 1u) {
    cnt[u] = 1;
    cur += d;
  }

  for (auto [c, w] : adj[u]) {
    if (c != p) {
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

  fill(adj, adj + n + 1, vector<pair<int, int>>());
  fill(weight, weight + n + 1, 0);
  fill(cnt, cnt + n + 1, 0);

  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  cur = 0;
  dfs(1, 0, 0);

  priority_queue<pair<long long, int>> pq;
  for (int i = 2; i <= n; ++i) {
    pq.emplace(((weight[i] + 1) / 2) * cnt[i], i);
  }

  int ans = 0;
  while (cur > s) {
    auto [val, i] = pq.top();
    pq.pop();
    ++ans;
    cur -= val;
    weight[i] /= 2;
    if (weight[i] > 0) {
      pq.emplace(((weight[i] + 1) / 2) * cnt[i], i);
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