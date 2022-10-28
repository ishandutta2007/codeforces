#include <bits/stdc++.h>
using namespace std;

const string S[] = {"MW", "LW", "LM"};
const int N = 25;

int a[N][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
    }
  }

  map<array<int, 2>, array<int, 2>> mask;
  for (int i = 0, m = pow(3, n / 2); i < m; ++i) {
    int k = i, d0 = 0, d1 = 0, d2 = 0;
    for (int j = 0; j < n / 2; ++j) {
      if (k % 3 != 0) {
        d0 += a[j][0], d1 -= a[j][0], d2 -= a[j][0];
      }
      if (k % 3 != 1) {
        d1 += a[j][1];
      }
      if (k % 3 != 2) {
        d2 += a[j][2];
      }
      k /= 3;
    }

    if (mask.count({d1, d2}) == 0 || d0 > mask[{d1, d2}][0]) {
      mask[{d1, d2}] = {d0, i};
    }
  }

  array<int, 3> ans = {INT_MIN, 0, 0};
  for (int i = 0, m = pow(3, (n + 1) / 2); i < m; ++i) {
    int k = i, d0 = 0, d1 = 0, d2 = 0;
    for (int j = n / 2; j < n; ++j) {
      if (k % 3 != 0) {
        d0 += a[j][0], d1 += a[j][0], d2 += a[j][0];
      }
      if (k % 3 != 1) {
        d1 -= a[j][1];
      }
      if (k % 3 != 2) {
        d2 -= a[j][2];
      }
      k /= 3;
    }

    if (mask.count({d1, d2})) {
      ans = max(ans, array<int, 3>{mask[{d1, d2}][0] + d0, mask[{d1, d2}][1], i});
    }
  }

  if (ans[0] == INT_MIN) {
    cout << "Impossible\n";
  } else {
    auto [x, y, z] = ans;
    for (int i = 0; i < n / 2; ++i) {
      cout << S[y % 3] << "\n";
      y /= 3;
    }
    for (int i = 0; i < (n + 1) / 2; ++i) {
      cout << S[z % 3] << "\n";
      z /= 3;
    }
  }
}