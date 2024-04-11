#include <bits/stdc++.h>
using namespace std;

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  string ans;
  if (n % 2 == 1) {
    ans += '0';
  }

  for (int i = 1; i <= n; ++i) {
    int prefix = 0;
    int suffix = 0;
    int res = t;

    int l = i;
    int r = i + n % 2;
    if (r > n) {
      break;
    }

    for (int j : {0, 1}) {
      while (prefix == j || suffix == j) {
        int res_new = query(l, r);
        if ((res_new % 2 == res % 2) ^ (r % 2 == 1)) {
          prefix ^= 1;
        } else {
          suffix ^= 1;
        }
        res = res_new;
      }

      if (j == 0) {
        res = n - res;
        if (n % 2 == 0) {
          ans += (res == t - 1 ? '1' : '0');
        } else {
          if (res == t) {
            ans += '1' + '0' - ans.back();
          } else {
            ans += ans.back();
          }
        }
        res = n - res;
      }
    }
  }

  if (count(ans.begin(), ans.end(), '1') != t) {
    for (auto &i : ans) {
      i = '0' + '1' - i;
    }
  }

  cout << "! " << ans << endl;
}