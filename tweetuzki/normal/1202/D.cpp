#include <bits/stdc++.h>
using namespace std;

long long f[10005];
int dif[10005];

int main() {
  int T, n;
  cin >> T;
  for (int i = 1; i <= 10000; ++i)
    f[i] = 1LL * i * (i + 1) / 2;
//  for (int i = 1; i <= 1000; ++i)
//    f[i] += f[i - 1];
  for (int t = 1; t <= T; ++t) {
    memset(dif, 0, sizeof dif);
    cin >> n;
    for (int i = 10000; i >= 1; --i) {
      while (n >= f[i]) {
        dif[i]++;
        n -= f[i];
//        printf("-= %lld\n", f[i]);
      }
    }
//    for (int i = 1000; i >= 1; --i) dif[i] += dif[i + 1];
    string ans = "13";
    for (int i = 1; i <= 10000; ++i) {
      ans += "3";
      for (int j = 1; j <= dif[i]; ++j) ans += "7";
    }
    cout << ans << endl;
  }
  return 0;
}