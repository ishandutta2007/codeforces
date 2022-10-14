#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int left_j = -1;
    for (int i = 0; i < n; i++) {
      if (i <= a[i]) {
        left_j++;
      } else {
        break;
      }
    }
    int right_j = -1;
    for (int i = n - 1; i >= 0; i--) {
      if ((n - i - 1) <= a[i]) {
        right_j = i;
      } else {
        break;
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (left_j >= i && right_j <= i && a[i] >= i - 1 && a[i] >= (n - i - 1)) {
        ok = true;
        break;
      }
    }
    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}