#include <bits/stdc++.h>
using namespace std;

int a[4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }

  int zero = 1;
  while (zero * (zero - 1) / 2 < a[0]) {
    ++zero;
  }

  int one = 1;
  while (one * (one - 1) / 2 < a[3]) {
    ++one;
  }

  if (zero * (zero - 1) / 2 != a[0] || one * (one - 1) / 2 != a[3]) {
    cout << "Impossible\n";
    exit(0);
  }

  if (a[1] + a[2] != zero * one) {
    if (zero == 1) {
      zero = 0;
    } else if (one == 1) {
      one = 0;
    }

    if (a[1] + a[2] != zero * one) {
      cout << "Impossible\n";
      exit(0);
    }
  }

  string ans(zero, '0');
  while (a[1] >= zero && one > 0) {
    a[1] -= zero;
    ans += '1';
    --one;
  }

  if (one > 0) {
    ans.insert(ans.begin() + a[1], '1');
    ans = string(one - 1, '1') + ans;
  }

  cout << ans << "\n";
}