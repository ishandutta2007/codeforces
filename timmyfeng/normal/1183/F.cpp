#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int skip[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    n = unique(a, a + n) - a;

    for (int i = 0; i < n; ++i) {
      skip[i] = i + 1;
      while (skip[i] < n && a[i] % a[skip[i]] == 0) {
        ++skip[i];
      }
    }

    int ans = 0;
    for (int i = 0; i < n && a[i] * 3 > ans; ++i) {
      ans = max(ans, a[i]);
      if (skip[i] < n) {
        ans = max(ans, a[i] + a[skip[i]]);

        int j = skip[skip[i]];
        while (j < n && (a[i] % a[j] == 0 || a[skip[i]] % a[j] == 0)) {
          ++j;
        }

        if (j < n) {
          ans = max(ans, a[i] + a[skip[i]] + a[j]);
        }
      }
    }

    cout << ans << "\n";
  }
}