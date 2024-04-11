#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  constexpr int kC = 1'000'000;
  vector<int> dv(kC + 1), pr;
  vector<int> rv(kC + 1, -1);
  for (int i = 2; i <= kC; ++i) {
    if (!dv[i]) {
      dv[i] = i;
      rv[i] = pr.size() + 1;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= kC; ++j) {
      dv[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
  constexpr int kM = 168;
  vector<int> counts(kC + 1);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> g(pr.size());
  vector<vector<int>> kv(kC + 1);
  map<int, int> pf;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int ph = 0, val = 1;
    vector<int> ps;
    while (a[i] > 1) {
      int d = dv[a[i]], cnt = 0;
      while (a[i] % d == 0) {
        a[i] /= d;
        cnt++;
      }
      if (cnt & 1) {
        ps.push_back(d);
        val *= d;
      }
      ph++;
    }
    assert(ph <= 2);
    if (ps.empty()) {
      cout << "1\n";
      return 0;
    }
    pf[val]++;
    if (ps.size() == 1) {
      g[0].push_back(rv[ps[0]]);
      g[rv[ps[0]]].push_back(0);
    } else {
      g[rv[ps[0]]].push_back(rv[ps[1]]);
      g[rv[ps[1]]].push_back(rv[ps[0]]);
    }
  }
  for (int i = 1; i <= kC; ++i) {
    if (counts[i] >= 2) {
      cout << "2\n";
      return 0;
    }
  }
  for (auto it : pf) {
    if (it.second >= 2) {
      cout << "2\n";
      return 0;
    }
  }
  int res = n + 1;
  for (int i = 0; i <= kM; ++i) {
    vector<int> dist(pr.size(), -1);
    dist[i] = 0;
    vector<int> que(1, i);
    int cycle = n + 1;
    for (int it = 0; it < que.size(); ++it) {
      int x = que[it];
      for (int u : g[x]) {
        if (dist[u] == -1) {
          dist[u] = dist[x] + 1;
          que.push_back(u);
        } else {
          if (dist[u] >= dist[x]) {
            cycle = min(cycle, dist[u] + dist[x] + 1);
          }
        }
      }
    }
    res = min(res, cycle);
  }
  if (res > n) res = -1;
  cout << res << "\n";
}