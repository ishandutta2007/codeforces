#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &i : b) {
      cin >> i;
      --i;
    }

    int maxi = n;
    for (int i = 0, j = 0, k = 0; i < 2 * n; ++i) {
      for ( ; j < n && b[j] < i; ++j);
      if (b[j] == i) {
        if (k) {
          --maxi, --k;
        }
      } else {
        ++k;
      }
    }

    int mini = 0;
    for (int i = 2 * n - 1, j = n - 1, k = 0; i >= 0; --i) {
      for ( ; j >= 0 && b[j] > i; --j);
      if (b[j] == i) {
        if (k) {
          ++mini, --k;
        }
      } else {
        ++k;
      }
    }

    cout << mini - maxi + 1 << "\n";
  }
}