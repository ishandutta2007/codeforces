#include <bits/stdc++.h>
using namespace std;

int a[6];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 6; ++i) {
    cin >> a[i];
  }

  int ans = 0;

  int x = 2 * a[0] - 1, l = a[5], r = a[1];
  bool lower_l = false, lower_r = false;
  while (!lower_l || l > 0) {
    if (!lower_l) {
      ++x;
    }
    if (l == 0) {
      lower_l = true;
      l = a[4];
    }
    --l;
    if (lower_l) {
      --x;
    }

    if (!lower_r) {
      ++x;
    }
    if (r == 0) {
      lower_r = true;
      r = a[2];
    }
    --r;
    if (lower_r) {
      --x;
    }

    ans += x;
  }

  cout << ans << "\n";
}