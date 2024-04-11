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
    int mn = min_element(a.begin(), a.end()) - a.begin();
    int mx = max_element(a.begin(), a.end()) - a.begin();
    cout << min({max(mn, mx) + 1, n - min(mn, mx), min(mn, mx) + 1 + n - max(mn, mx)}) << '\n';
  }
  return 0;
}