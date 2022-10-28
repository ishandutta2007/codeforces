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

    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());

    int m = a[n - 1];
    vector<int> where(m + 1, -1);
    for (int i = 0; i < n; ++i) {
      if (where[a[i]] == -1) {
        where[a[i]] = i;
      }
    }

    vector<int> ans(n, 1);
    for (int i = 0; i < n; ++i) {
      if (i < n - 1 && a[i + 1] == a[i]) {
        ans[i + 1] = max(ans[i + 1], ans[i] + 1);
        continue;
      }

      for (int j = 2 * a[i]; j <= m; j += a[i]) {
        if (where[j] != -1) {
          ans[where[j]] = max(ans[where[j]], ans[i] + 1);
        }
      }
    }

    cout << n - *max_element(ans.begin(), ans.end()) << "\n";
  }
}