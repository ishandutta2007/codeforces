#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> dv(200000 + 1);
  vector<int> pr;
  for (int i = 2; i <= 200000; ++i) {
    if (!dv[i]) {
      dv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= 200000; ++j) {
      dv[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
  vector<vector<int>> pv(200000 + 1);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    while (a[i] > 1) {
      int d = dv[a[i]], cnt = 0;
      while (a[i] % d == 0) {
        a[i] /= d;
        cnt++;
      }
      pv[d].push_back(cnt);
    }
  }
  int64_t res = 1;
  for (int u : pr) {
    sort(pv[u].begin(), pv[u].end());
    if (n - pv[u].size() >= 2) continue;
    if (n - pv[u].size() == 1) {
      int g = pv[u][0];
      for (int i = 0; i < g; ++i) res *= u;
    } else {
      int g = pv[u][1];
      for (int i = 0; i < g; ++i) res *= u;
    }
  }
  cout << res << "\n";
}