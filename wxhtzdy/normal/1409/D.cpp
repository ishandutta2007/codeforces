/**
 *  author: milos
 *  created: 05.10.2020 12:53:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    int s;
    cin >> s;
    auto ok = [&](long long k) {
      int sum = 0;
      while (k > 0) {
        sum += k % 10;
        k /= 10;
      }
      return sum <= s;
    };
    if (ok(n)) {
      cout << 0 << '\n';
      continue;
    }
    auto Get = [&](int pos) {
      long long k = n;
      int cnt = 0;
      while (cnt < pos) {
        cnt++;
        k /= 10;
      }
      return k % 10;
    };
    long long ans = 0, tn = 1;
    for (int i = 0; i < 19; i++) {
      int dgt = Get(i);   
      dgt = (10 - dgt) % 10;
      ans += dgt * (long long) tn;
      n += dgt * (long long) tn;
      if (i < 19) {
        tn *= 10;
      }//cout << dgt << " " << ans << '\n';
      if (ok(n)) {
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}