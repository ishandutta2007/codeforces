#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int m, d, w;
    cin >> m >> d >> w;
    int k = (d - 1) % w;
    int n = min(m, d);
    int diff = w / __gcd(k, w);
    long long cnt = n / diff;
    long long ans = cnt * (cnt - 1) / 2 * diff + cnt * (n % diff);
    cout << ans << "\n";
  }
}