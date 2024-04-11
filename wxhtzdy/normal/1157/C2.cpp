/**
 *    author:  milos
 *    created: 13.04.2021 22:55:32       
**/
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
  int l = 0, r = n - 1, val = 0;
  string ans = "";
  while (l <= r) {
    if (a[l] <= val && a[r] <= val) {
      break;
    }   
    int pos = -1;
    if (a[l] > val) {
      pos = l;
    }
    if (a[r] > val) {
      if (pos != -1) {
        if (a[r] < a[l]) {
          pos = r;
        }
      } else {
        pos = r;
      }
    }
    if (a[l] == a[r]) {
      int x = 1, y = 1;
      for (int j = l + 1; j <= r; j++) {
        if (a[j] > a[j - 1]) {
          x++;
        } else {
          break;
        }
      }
      for (int j = r - 1; j >= l; j--) {
        if (a[j] > a[j + 1]) {
          y++;
        } else {
          break;
        }
      }
      int mx = max(x, y);
      for (int i = 0; i < mx; i++) {
        if (x == mx) {
          ans += 'L';
        } else {
          ans += 'R';
        }
      }
      break;
    }
    if (pos == -1) {
      break;
    }
    val = a[pos];
    if (pos == l) ans += 'L', l++;
    else ans += 'R', r--;
  }
  cout << ans.size() << '\n' << ans << '\n';
  return 0;
}