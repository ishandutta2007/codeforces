#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q; 
  cin >> q;
  while (q--) {
    int n; 
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
      p[i] /= 100;
    }
    sort(p.rbegin(), p.rend());
    int x, y, a, b;
    cin >> x >> a >> y >> b;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      if ((i + 1) % a == 0 && (i + 1) % b == 0) v.emplace_back(i, x + y);
      else if ((i + 1) % a == 0) v.emplace_back(i, x);
      else if ((i + 1) % b == 0) v.emplace_back(i, y);
    }

    auto Solve = [&](int r) {
      vector<pair<int, int>> w(v.begin(), v.begin() + r + 1);
      sort(w.begin(), w.end(), [&](auto a, auto b) { return a.second > b.second; });
      assert(w.size() == r + 1);
      // cerr << "solve r = " << r << "\n";
      int64_t sum = 0;
      for (int i = 0; i <= r; ++i) {
        // cerr << "p[i] = " << p[i] << " w[i].second = " << w[i].second << "\n";
        sum += 1LL * p[i] * w[i].second;
      }
      // cerr << " sum = " << sum << "\n";
      return sum;
    };

    int64_t k;
    cin >> k;
    int ans = v.size();
    for (int d = 20; d >= 0; --d) {
      if (ans - (1 << d) < 0) continue;
      if (Solve(ans - (1 << d)) >= k) ans -= (1 << d);
    }
    if (ans == v.size()) cout << -1 << "\n";
    else cout << v[ans].first + 1 << "\n";
  }
}