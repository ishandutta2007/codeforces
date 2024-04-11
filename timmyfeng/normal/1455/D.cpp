#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int ans = 0;
    while (true) {
      bool sorted = true;
      for (int i = 1; i < n; ++i) {
        sorted &= (a[i] >= a[i - 1]);
      }

      if (sorted) {
        break;
      }

      int i = 0;
      while (i < n && a[i] <= x) {
        ++i;
      }

      if (i == n) {
        ans = -1;
        break;
      }

      swap(a[i], x);
      ++ans;
    }

    cout << ans << "\n";
  }
}