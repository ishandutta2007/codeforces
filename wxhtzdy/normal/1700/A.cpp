#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    long long a = 0;
    long long b = 0;
    for (int i = 1; i <= m; i++) {
      a += i;
    }
    for (int i = 2 * m; i <= n * m; i += m) {
      a += i;
    }
    for (int i = 1; i <= n * m; i += m) {
      b += i;
    }
    for (int i = n * m - (m - 2); i <= n * m; i++) {
      b += i;
    }
    cout << min(a, b) << '\n';
  }
  return 0;
}