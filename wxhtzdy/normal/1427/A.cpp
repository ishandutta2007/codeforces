#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    if (sum == 0) {
      cout << "NO" << '\n';
      continue;
    }
    if (sum < 0) {
      sort(a.begin(), a.end());
    } else {
      sort(a.rbegin(), a.rend());
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}