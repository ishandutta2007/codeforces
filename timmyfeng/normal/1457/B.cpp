#include <bits/stdc++.h>
using namespace std;

const int C = 100;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> c(n);
    for (auto &i : c) {
      cin >> i;
    }

    int ans = n;
    for (int i = 1; i <= C; ++i) {
      int count = 0, covered = 0;
      for (int j = 0; j < n; ++j) {
        if (j >= covered && c[j] != i) {
          covered = j + k;
          ++count;
        }
      }
      ans = min(ans, count);
    }

    cout << ans << "\n";
  }
}