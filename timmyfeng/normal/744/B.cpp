#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 1;

int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  fill(ans + 1, ans + n + 1, INT_MAX);

  for (int i = 0; i <= __lg(n); ++i) {
    for (int k = 0; k < 2; ++k) {
      vector<int> values;
      for (int j = 1; j <= n; ++j) {
        int bit = (j & (1 << i)) > 0;
        if (bit == k) {
          values.push_back(j);
        }
      }

      cout << values.size() << endl;
      for (auto j : values) {
        cout << j << " ";
      }
      cout << endl;

      for (int j = 1; j <= n; ++j) {
        int a;
        cin >> a;
        int bit = (j & (1 << i)) > 0;
        if (bit != k) {
          ans[j] = min(ans[j], a);
        }
      }
    }
  }

  cout << -1 << endl;
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}