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
    long long odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      (i % 2 == 0 ? even : odd) += a[i];
    }

    for (int i = 0; i < n; ++i) {
      if ((odd > even) ^ (i % 2 == 1)) {
        cout << 1 << " ";
      } else {
        cout << a[i] << " ";
      }
    }
    cout << "\n";
  }
}