#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int j = n - 2;
    while (k--) {
      a[n - 1] += a[j];
      a[j] = 0;
      j--;
    }
    cout << a[n - 1] - 0 << '\n';
  }
  return 0;
}