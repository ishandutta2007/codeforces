#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> s(n);
  for (auto &i : s) {
    cin >> i;
  }

  int l = s[n - 1], r = 2 * s[n - 1];
  while (l < r) {
    int m = (l + r) / 2;

    int i = 0, j = n - 1, x = 0;
    while (i <= j) {
      if (s[i] + s[j] <= m) {
        ++i;
      }
      --j, ++x;
    }

    if (x <= k) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  cout << l << "\n";
}