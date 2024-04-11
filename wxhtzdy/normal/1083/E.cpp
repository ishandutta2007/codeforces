#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> a[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return x[i] < x[j];
  });
  vector<tuple<int, long long, long long>> lines;
  function<void(long long, long long)> AddLine = [&](long long k, long long d) {
    while (!lines.empty()) {
      if (k * get<0>(lines.back()) + d >= get<1>(lines.back()) * get<0>(lines.back()) + get<2>(lines.back())) {
        lines.pop_back();
      } else {
        break;
      }
    }
    if (lines.empty()) {
      lines.emplace_back(-1e9 - 1, k, d);
    } else {
      const long long inf = 1e9;
      long long l = get<0>(lines.back()), r = inf + 5;
      while (l + 1 < r) {
        long long mid = (l + r + 1) >> 1;
        if (mid * k + d >= mid * get<1>(lines.back()) + get<2>(lines.back())) {
          r = mid;
        } else {
          l = mid;
        }
      }
      if (r <= inf) {
        lines.emplace_back(r, k, d);
      }
    }
  };
  auto Get = [&](int v) {   
    auto it = prev(lower_bound(lines.begin(), lines.end(), make_tuple(v + 1, -1e9 - 5, -1e9 - 5)));
    auto val = *it;
    return get<1>(val) * 1LL * v + get<2>(val);
  };
  vector<long long> dp(n);
  AddLine(0, 0);
  for (int id = 0; id < n; id++) {
    int i = order[id];
    dp[i] = Get(-y[i]) + x[i] * 1LL * y[i] - a[i];
    AddLine(x[i], dp[i]);
  }                         
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}