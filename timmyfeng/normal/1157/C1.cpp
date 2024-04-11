#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  int l = 0, r = n - 1, x = 0;
  string ans;

  while (l <= r) {
    if (max(a[l], a[r]) <= x) {
      break;
    }

    bool ok = (a[l] <= x || (a[r] > x && a[r] < a[l]));
    if (a[l] == a[r]) {
      int u = 1, v = 1;
      while (l + u < r && a[l + u] > a[l + u - 1]) {
        ++u;
      }
      while (r - v > l && a[r - v] > a[r - v + 1]) {
        ++v;
      }
      ok = (v >= u);
    }

    if (ok) {
      ans += 'R';
      x = a[r--];
    } else {
      ans += 'L';
      x = a[l++];
    }
  }

  cout << ans.size() << "\n";
  cout << ans << "\n";
}