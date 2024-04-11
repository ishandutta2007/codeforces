/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 15:40:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto Calc = [&](int i) {
    if (i < 0 || i >= n) {
      return 0LL;
    }
    if (i == 0) {
      return (long long) n;
    } else {    
      if (a[i] != a[i - 1]) {
        return (i + 1) * 1LL * (n - i);
      } else {
        return (long long) n - i;
      }
    }
  };
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += Calc(i);
  }
  while (m--) {
    int i, x;
    cin >> i >> x;
    --i;
    ans -= Calc(i);
    ans -= Calc(i + 1);
    a[i] = x;
    ans += Calc(i);
    ans += Calc(i + 1);
    cout << ans << '\n';    
  }                                                    
  return 0;
}