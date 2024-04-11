#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }

    long long ans = 0;
    for (int i = 0; i * 2 < n; ++i) {
      for (int j = 0; j * 2 < m; ++j) {
        vector<int> values = {a[i][j]};
        bool row = (i * 2 + 1 < n);
        bool col = (j * 2 + 1 < m);
        if (row) {
          values.push_back(a[n - 1 - i][j]);
        }
        if (col) {
          values.push_back(a[i][m - 1 - j]);
        }
        if (row && col) {
          values.push_back(a[n - 1 - i][m - 1 - j]);
        }
        sort(values.begin(), values.end());

        int target = values[values.size() / 2];
        for (auto i : values) {
          ans += abs(target - i);
        }
      }
    }

    cout << ans << "\n";
  }
}