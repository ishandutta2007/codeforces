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

    int max_a = 0;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
      max_a = max(max_a, i);
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] == max_a) {
        if (i > 0 && a[i - 1] != max_a) {
          ans = i + 1;
        } else if (i < n - 1 && a[i + 1] != max_a) {
          ans = i + 1;
        }
      }
    }

    cout << ans << "\n";
  }
}