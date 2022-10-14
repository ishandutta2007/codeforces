/**
 *    author: m371
 *    created: 12.10.2021 20:42:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double n;
  cin >> n;
  double p;
  cin >> p;
  auto Can = [&](double m) {
    double total = n * 1LL * (n - 1) * 1LL * (n - 2) / 6;
    double p0 = (m * 1LL * (m - 1) * 1LL * (m - 2)) / 6;
    double p1 = (m * 1LL * (m - 1)) / 2 * 1LL * (n - m);
    double p2 = m * (((n - m) * (n - m - 1)) / 2);
    p0 = p0 / total;
    p1 = p1 / total;
    p2 = p2 / total;
    return (p0 + p1 + p2 * 0.5) >= p;      
  };
  int low = 0, high = n - 1, ans = -1;
  while (low <= high) {
    int mid = low + high >> 1;
    if (Can(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  assert(ans != -1);  
  cout << ans << '\n';
  return 0;
}