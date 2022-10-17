#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] <= i + 1) res = i + 2;
    }
    cout << res << "\n";
  }
}