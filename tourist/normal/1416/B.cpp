/**
 *    author:  tourist
 *    created: 27.09.2020 18:16:30       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n != 0) {
      cout << -1 << '\n';
      continue;
    }
    int avg = sum / n;
    vector<tuple<int, int, int>> ret;
    auto Do = [&](int i, int j, int x) {
      assert(a[i] >= x * i);
      ret.emplace_back(i, j, x);
      a[i] -= x * i;
      a[j] += x * i;
    };
    for (int i = 2; i <= n; i++) {
      int r = (i - a[i] % i) % i;
      Do(1, i, r);
      assert(a[i] % i == 0);
      Do(i, 1, a[i] / i);
    }
    for (int i = 2; i <= n; i++) {
      Do(1, i, avg);
    }
    cout << ret.size() << '\n';
    for (auto& t : ret) {
      cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';
    }
  }
  return 0;
}