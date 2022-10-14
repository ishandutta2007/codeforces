#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long l = 1;
    long long ans = 0;
    for (int i = 1;; i++) {
      l = (l * i) / __gcd(l, (long long) i);
      if (l > n) break;
      ans = (ans + n / l) % md;
    }
    cout << (ans + n) % md << '\n';
  }
  return 0;
}