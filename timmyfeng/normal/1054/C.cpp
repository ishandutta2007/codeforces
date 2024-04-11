#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int ans[N], l[N], r[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }

  for (int k = n; k > 0; --k) {
    for (int i = 0; i < n; ++i) {
      if (l[i] == 0 && r[i] == 0 && ans[i] == 0) {
        ans[i] = k;
      }
    }

    int prefix = 0;
    for (int i = 0; i < n; ++i) {
      if (ans[i] == k) {
        ++prefix;
      } else if (ans[i] == 0) {
        l[i] -= prefix;
      }
    }

    int suffix = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (ans[i] == k) {
        ++suffix;
      } else if (ans[i] == 0) {
        r[i] -= suffix;
      }
    }
  }

  if (count(ans, ans + n, 0) == 0) {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
}