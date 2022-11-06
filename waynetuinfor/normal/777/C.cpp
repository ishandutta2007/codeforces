#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
vector<pair<int, int>> a[maxn];
int n, m, k, best[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i <= m; ++i) a[0].push_back(make_pair(INT_MAX, 0));
  for (int i = 1; i <= n; ++i) {
    int x; a[i].push_back(make_pair(INT_MAX, 0));
    for (int j = 1; j <= m; ++j) cin >> x, a[i].push_back(make_pair(x, 0));
  }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 1; --j) {
      if (i < n) a[i][j].second = a[i + 1][j].first >= a[i][j].first ? a[i + 1][j].second + 1 : 1;
      else a[i][j].second = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) best[i] = max(best[i], a[i][j].second);
  }
  cin >> k;
  while (k--) {
    int l, r; cin >> l >> r;
    if (best[l] >= r - l + 1) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}