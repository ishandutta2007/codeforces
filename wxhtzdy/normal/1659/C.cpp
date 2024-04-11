#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    n += 1;
    vector<int> x(n);
    x[0] = 0;
    for (int i = 1; i < n; i++) {
      cin >> x[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += x[i] * 1LL * b;
    }
    long long nans = ans;
    for (int i = 1; i < n; i++) {
      long long d = x[i] - x[i - 1];
      nans -= d * (n - i - 1) * b;
      nans += d * a;
      ans = min(ans, nans);
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}