#include <bits/stdc++.h>
using namespace std;

int a[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto &i : a) {
    cin >> i;
  }

  int l;
  cin >> l;

  long long ans = 1;
  for (int i = 0; i < 3; ++i) {
    ans *= l + 3 - i;
    ans /= i + 1;
  }

  for (int i = 0; i <= l; ++i) {
    for (int j = 0; j < 3; ++j) {
      int sum = 2 * a[j] + i - accumulate(a, a + 3, 0);
      if (sum >= 0) {
        sum = min(sum, l - i);
        ans -= (long long) (sum + 1) * (sum + 2) / 2;
      }
    }
  }

  cout << ans << "\n";
}