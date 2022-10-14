#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    string ans = "";
    int x = 0, y = 0, z = 0;
    while (x < 2 * n && y < 2 * n && z < 2 * n) {
      vector<int> cnt(3);
      cnt[a[x] - '0']++;
      cnt[b[y] - '0']++;
      cnt[c[z] - '0']++;
      if (cnt[1] > cnt[0]) {
        if (a[x] == '1') x++;
        if (b[y] == '1') y++;
        if (c[z] == '1') z++;
        ans += '1';
      } else {
        if (a[x] == '0') x++;
        if (b[y] == '0') y++;
        if (c[z] == '0') z++;
        ans += '0';
      }
    }
    if (x == 2 * n) {
      if (y > z && y < 2 * n) {
        for (int i = y; i < 2 * n; i++) {
          ans += b[i];
        }
      } else {
        if (z >= y && z < 2 * n) {
          for (int i = z; i < 2 * n; i++) {
            ans += c[i];
          }
        }
      }
    } else {
      if (y == 2 * n) {
        if (x > z && x < 2 * n) {
          for (int i = x; i < 2 * n; i++) {
            ans += a[i];
          }
        } else {
          if (z >= x && z < 2 * n) {
            for (int i = z; i < 2 * n; i++) {
              ans += c[i];
            }
          }
        }
      } else {
        if (x > y && y < 2 * n) {
          for (int i = x; i < 2 * n; i++) {
            ans += a[i];
          }
        } else {
          if (y >= x && y < 2 * n) {
            for (int i = y; i < 2 * n; i++) {
              ans += b[i];
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}