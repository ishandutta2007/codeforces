/**
 *  author: milos
 *  created: 04.01.2021 04:09:01
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
    cin >> c >> b >> a;
    int x, y, z;
    cin >> z >> y >> x;
    int r = min(a, y), ans = 0;
    ans += r * 2;
    a -= r, y -= r;
    r = min(a, x);
    a -= r, x -= r;
    a = max(a, 0);
    x = max(x, 0);

    r = min(a, z);
    a -= r, z -= r;
    a = max(a, 0);
    z = max(z, 0);

    r = min(c, x);
    c -= r, x -= r;
    c = max(c, 0);
    x = max(x, 0);
        
    r = min(c, y);
    c -= r, y -= r;
    c = max(c, 0);
    y = max(y, 0);

    r = min(c, z);
    c -= r, z -= r;
    c = max(c, 0);
    z = max(z, 0);
        
    r = min(b, z);
    b -= z, z -= r;
    b = max(b, 0);
    z = max(z, 0);

    r = min(b, y);
    b -= r, y -= r;
    b = max(b, 0);
    y = max(y, 0);

    r = min(b, x);
    ans -= r * 2;
    b -= x, z -= r;

    cout << ans << '\n';
  }
  return 0;
}