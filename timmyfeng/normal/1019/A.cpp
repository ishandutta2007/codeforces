#include <bits/stdc++.h>
using namespace std;

const int N = 3001;

vector<int> cost[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int cnt = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      ++cnt;
    } else {
      cost[a].push_back(b);
      ans += b;
    }
  }

  for (int i = 2; i <= m; ++i) {
    sort(cost[i].begin(), cost[i].end());
  }

  for (int i = cnt; i <= n; ++i) {
    int cur = cnt;
    vector<int> ext;
    long long res = 0;
    for (int j = 2; j <= m; ++j) {
      for (int k = 0; k < int(cost[j].size()); ++k) {
        if (int(cost[j].size()) - k >= i) {
          res += cost[j][k];
          ++cur;
        } else {
          ext.push_back(cost[j][k]);
        }
      }
    }
    sort(ext.begin(), ext.end());
    for (int j = 0; j < i - cur; ++j) {
      res += ext[j];
    }
    ans = min(ans, res);
  }
  cout << ans << "\n";
}