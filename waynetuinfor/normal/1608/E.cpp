#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<tuple<int, int, int>> xp(N);
  for (int i = 0; i < N; ++i) {
    cin >> get<0>(xp[i]) >> get<1>(xp[i]) >> get<2>(xp[i]);
    get<2>(xp[i])--;
  }
  vector<tuple<int, int, int>> yp = xp;
  for (auto& [x, y, c] : yp) {
    swap(x, y);
  }
  sort(xp.begin(), xp.end());
  sort(yp.begin(), yp.end());

  auto xpr = xp, ypr = yp;
  for (auto& [x, y, c] : xpr) {
    x = -x;
    y = -y;
  }
  for (auto& [y, x, c] : ypr) {
    x = -x;
    y = -y;
  }
  sort(xpr.begin(), xpr.end());
  sort(ypr.begin(), ypr.end());

  constexpr int kInf = 1'000'000'000;

  auto Check = [&](const vector<tuple<int, int, int>>& xp,
                   const vector<tuple<int, int, int>>& yp, int k) {
    vector<int> order = {0, 1, 2};
    do {
      int cnt = 0, xm = -kInf;
      for (int i = 0; i < N; ++i) {
        if (get<2>(xp[i]) == order[0]) {
          if (++cnt == k) {
            xm = get<0>(xp[i]);
            break;
          }
        }
      }
      assert(cnt == k);
      cnt = 0;
      int xr = -kInf;
      for (int i = 0; i < N; ++i) {
        if (get<0>(xp[i]) <= xm) continue;
        if (get<2>(xp[i]) == order[1]) {
          if (++cnt == k) {
            xr = get<0>(xp[i]);
            break;
          }
        }
      }
      if (cnt == k) {
        cnt = 0;
        for (int i = 0; i < N; ++i) {
          if (get<0>(xp[i]) <= xr) continue;
          if (get<2>(xp[i]) == order[2]) {
            if (++cnt == k) {
              return true;
            }
          }
        }
      }
      cnt = 0;
      int ym = -kInf;
      for (int i = 0; i < N; ++i) {
        if (get<1>(yp[i]) <= xm) continue;
        if (get<2>(yp[i]) == order[1]) {
          if (++cnt == k) {
            ym = get<0>(yp[i]);
            break;
          }
        }
      }
      if (cnt == k) {
        cnt = 0;
        for (int i = 0; i < N; ++i) {
          if (get<1>(yp[i]) <= xm || get<0>(yp[i]) <= ym) continue;
          if (get<2>(yp[i]) == order[2]) {
            if (++cnt == k) {
              return true;
            }
          }
        }
      }
    } while (next_permutation(order.begin(), order.end()));
    return false;
  };

  int ans = 0;
  for (int bit = 20; bit >= 0; --bit) {
    if (ans + (1 << bit) <= N / 3) {
      if (Check(xp, yp, ans + (1 << bit)) || Check(yp, xp, ans + (1 << bit)) ||
          Check(xpr, ypr, ans + (1 << bit)) ||
          Check(ypr, xpr, ans + (1 << bit))) {
        ans += (1 << bit);
      }
    }
  }
  cout << ans * 3 << "\n";
  return 0;
}