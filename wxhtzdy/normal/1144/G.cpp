#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> x, y;
  int last_x = -1, last_y = 1e9;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    bool mudja = false, cale = false;
    if (a[i] > last_x) {
      mudja = true;
    }
    if (a[i] < last_y) {
      cale = true;
    }
    if (!mudja && !cale) {
      cout << "NO" << '\n';
      return 0;
    } else {
      if (mudja && !cale) {
        last_x = a[i];
        ans[i] = 0;
      } else {
        if (!mudja && cale) {
          last_y = a[i];
          ans[i] = 1;
        } else {
          if (i == n - 1 || a[i] < a[i + 1]) {
            last_x = a[i];
            ans[i] = 0;
          } else {
            last_y = a[i];
            ans[i] = 1;
          }
        }
      }
    }
  }
  last_x = -1, last_y = 1e9;
  for (int i = 0; i < n; i++) {
    if (ans[i] == 0) {
      if (a[i] <= last_x) {
        cout << "NO" << '\n';
        return 0;
      }
      last_x = a[i];
    } else {
      if (a[i] >= last_y) {
        cout << "NO" << '\n';
        return 0;
      }
      last_y = a[i];
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  return 0;
}