#include <bits/stdc++.h>
using namespace std;

int main() {
  //
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }
  int64_t ans = 0;
  for (int i = n - k + 1; i <= n; ++i) ans += i;
  constexpr int kMod = 998244353;
  vector<int> p;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= n - k) {
      p.push_back(i);
    }
  }
  int res = 1;
  for (int i = 0; i + 1 < p.size(); ++i) {
    int dist = p[i + 1] - p[i];
    res = 1LL * res * dist % kMod;
  }
  cout << ans << " " << res << "\n";
}