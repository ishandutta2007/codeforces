/**
 *  author: milos
 *  created: 27.09.2020 01:08:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1e9, xa = a, xb = b, xc = c;
    for (int i = 1; i <= 2 * a; i++) {
      for (int j = i; j <= 2 * b; j += i) {
        if (j % i != 0) {
          continue;
        }
        int new_a = i, new_b = j, k1 = (c / j) * j, k2 = (c / j) * j + j;
        int dist1 = abs(a - new_a) + abs(b - new_b) + abs(c - k1);
        int dist2 = abs(a - new_a) + abs(b - new_b) + abs(c - k2);
        if (dist1 < ans) {
          ans = dist1;
          xa = new_a;
          xb = new_b;
          xc = k1;
        }
        if (dist2 < ans) {
          ans = dist2;
          xa = new_a;
          xb = new_b;
          xc = k2;
        }
      }
    }
    cout << ans << '\n' << xa << " " << xb << " " << xc << '\n';
  }
  return 0;
}