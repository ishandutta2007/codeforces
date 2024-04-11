/**
 *    author:  wxhtzdy
 *    created: 12.09.2022 17:04:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  auto Ask = [&](long long a, long long b) {
    assert(a != b);
    cout << "? " << a << " " << b << endl;
    long long x;
    cin >> x;
    return x;
  };                
  long long ans = 3;
  vector<pair<int, int>> v;
  for (int i = 1; i <= 100; i++) {
    for (int j = i + 1; j <= 100; j++) {
      v.emplace_back(i, j);
    }
  }
  sort(v.begin(), v.end(), [&](pair<int, int> x, pair<int, int> y) {
    return max(x.first, x.second) < max(y.first, y.second);
  });  
  for (int i = 0; i < 25; i++) {
    long long x = Ask(v[i].first, v[i].second);
    long long y = Ask(v[i].second, v[i].first);
    if (x == -1) {
      assert(y == -1);
      cout << "! " << max(v[i].first, v[i].second) - 1 << endl;
      return 0;
    }
    if (x != y) {
      cout << "! " << x + y << endl;
      return 0;
    } else {
      ans = max(ans, x);
    }
  }                             
  cout << "! " << ans << endl;
  return 0;
}