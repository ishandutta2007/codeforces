#include <bits/stdc++.h>
#define double long double
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<pair<int, int>, vector<tuple<double, int, int>>> pt;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) continue;
    int g = __gcd(abs(x), abs(y));
    int gx = x / g;
    int gy = y / g;
    double dist = hypotl(x, y);
    pt[make_pair(gx, gy)].emplace_back(dist, x, y);
  }
  auto Solve = [&](int v, vector<vector<tuple<double, int, int>>> pv) {
    vector<int> take(pv.size(), k - 1);
    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < pv.size(); ++i) {
      pq.emplace((k - 1) * get<0>(pv[i].back()), i);
    }
    double res = 0.0;
    while (v > 0 && !pq.empty()) {
      int g = pq.top().second;
      res += pq.top().first;
      pq.pop();
      pv[g].pop_back();
      take[g] -= 2;  
      if (take[g] > 0 && !pv[g].empty()) {
        pq.emplace(take[g] * get<0>(pv[g].back()), g);
      }
      v--;
    }
    if (v == 0) return res;
    while (!pq.empty()) pq.pop();
    for (int i = 0; i < pv.size(); ++i) {
      double ps = 0.0;
      for (int j = 0; j < pv[i].size(); ++j) {
        double s = -2 * ps + take[i] * get<0>(pv[i][j]);
        ps += get<0>(pv[i][j]);
        get<0>(pv[i][j]) = s;
      }
      reverse(pv[i].begin(), pv[i].end());
      if (!pv[i].empty()) {
        pq.emplace(get<0>(pv[i].back()), i);
      }
    }
    while (v > 0) {
      int g = pq.top().second;
      pq.pop();
      res += get<0>(pv[g].back());
      pv[g].pop_back();
      if (!pv[g].empty()) {
        pq.emplace(get<0>(pv[g].back()), g);
      }
      v--;
    }
    assert(v == 0);
    return res;
  };

  vector<vector<tuple<double, int, int>>> pv;
  for (auto it : pt) {
    pv.push_back(it.second);
  }
  for (int i = 0; i < pv.size(); ++i) {
    sort(pv[i].begin(), pv[i].end());
  }
  auto clone = pv;
  double res = Solve(k - 1, pv);
  assert(pv == clone);
  if (k < n) {
    res = max(res, Solve(k, pv));
  }
  cout << fixed << setprecision(20) << res << "\n";
  return 0;
}