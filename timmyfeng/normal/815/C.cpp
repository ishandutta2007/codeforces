#include <bits/stdc++.h>
using namespace std;

const int N = 5'000;

vector<int> adj[N];
int discount[N];
int cost[N];
int sub[N];

array<vector<long long>, 2> dfs(int u) {
  vector<long long> dp_yes = {LLONG_MAX / 2, cost[u] - discount[u]};
  vector<long long> dp_no = {0, cost[u]};
  sub[u] = 1;

  for (auto c : adj[u]) {
    auto [chd_no, chd_yes] = dfs(c);

    vector<long long> new_no(sub[u] + sub[c] + 1, LLONG_MAX / 2);
    vector<long long> new_yes(sub[u] + sub[c] + 1, LLONG_MAX / 2);

    for (int i = 0; i <= sub[c]; ++i) {
      for (int j = 0; j <= sub[u]; ++j) {
        new_no[i + j] = min(new_no[i + j], chd_no[i] + dp_no[j]);
        new_yes[i + j] = min(new_yes[i + j], min(chd_no[i], chd_yes[i]) + dp_yes[j]);
      }
    }

    sub[u] += sub[c];
    swap(dp_no, new_no);
    swap(dp_yes, new_yes);
  }

  return {dp_no, dp_yes};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, b;
  cin >> n >> b;

  for (int i = 0; i < n; ++i) {
    cin >> cost[i] >> discount[i];
    if (i > 0) {
      int p;
      cin >> p;
      adj[p - 1].push_back(i);
    }
  }

  auto [dp_no, dp_yes] = dfs(0);

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (dp_no[i] <= b || dp_yes[i] <= b) {
      ans = i;
    }
  }
  cout << ans << "\n";
}