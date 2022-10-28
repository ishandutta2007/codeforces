#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, cnt_l, cnt_e, v;
  cin >> n >> m >> cnt_l >> cnt_e >> v;

  vector<int> l(cnt_l);
  for (auto& i : l) {
    cin >> i;
  }

  vector<int> e(cnt_e);
  for (auto& i : e) {
    cin >> i;
  }

  auto get = [&](const vector<int>& a, int b, int c) {
    auto it = lower_bound(a.begin(), a.end(), min(b, c));
    int res = 1e9;
    for (int i = 0; i < 2; ++i) {
      if (it != a.end()) {
        res = min(res, abs(*it - b) + abs(*it - c));
      }
      if (it != a.begin()) {
        --it;
      }
    }
    return res;
  };

  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int delta = abs(x2 - x1);
    if (delta == 0) {
      cout << abs(y1 - y2) << "\n";
    } else {
      cout << min(get(l, y1, y2) + delta, get(e, y1, y2) + (delta - 1) / v + 1) << "\n";
    }
  }
}