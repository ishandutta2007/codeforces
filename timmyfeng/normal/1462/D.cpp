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
    int sum = 0;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
      sum += i;
    }

    int ans = n;
    for (int i = 1; i <= n; ++i) {
      if (sum % i == 0) {
        int block = sum / i, current = 0;
        bool ok = true;
        for (int j = 0; j < n; ++j) {
          current += a[j];
          if (current > block) {
            ok = false;
          } else if (current == block) {
            current = 0;
          }
        }

        if (ok) {
          ans = n - i;
        }
      }
    }

    cout << ans << "\n";
  }
}